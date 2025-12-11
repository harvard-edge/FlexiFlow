# FlexiFlow Workflows

## Table of Contents
- [Instruction-level Workflow](#instruction-level-workflow)
- [Cycle-level Workflow](#cycle-level-workflow)
- [Kernel Ablation Workflow](#kernel-ablation-workflow)

## Instruction-level Workflow

This workflow uses an instruction-level simulator (`spike`) to execute
benchmarks and gather instruction traces. Analysis of instruction-level results
can be found [here](instruction-level/InstructionLevelAnalysis.ipynb).

### Compiling Benchmarks
To compile the benchmarks, you can use the provided `Makefile` in this directory. First, update the `RV_PREFIX` variable in the `Makefile` to point to your local RISC-V toolchain installation.

You can compile a specific SDG benchmark by running:
```bash
make [SDG_TARGET]
```
For example, to compile the SDG 2 benchmark, run:
```bash
make SDG_02
```

You can also specify the inference mode and data sample number:

| Option            | Values            | Description                                                                              |
| ----------------- | ----------------- | ---------------------------------------------------------------------------------------- |
| `INFERENCE`       | `single`, `multi` | `single` (default) for single-sample executable, `multi` for multi-sample verification,. |
| `DATA_SAMPLE_NUM` | `0-N`             | Specifies the data sample to use for single-inference (default: 0).                      |
| `QUANTIZATION`    | `0-32`            | Specifies the quantization level (limited support, 0 = default quantization).            |

For example, to compile the SDG 2 benchmark for multi-inference with 8-bit quantization, run:
```bash
make SDG_02 INFERENCE=multi QUANTIZATION=8
```

The compiled binaries will be placed in the `build/bin/` directory. The `build/obj/` directory contains the object files, and the `build/src/` directory contains the preprocessed source files.

### Instruction-level simulation

Instruction-level simulation is performed using `spike`, the RISC-V ISA simulator.

After compiling a workload, you can simulate it with `spike`:
```bash
spike -l --isa=rv32e ../build/bin/[SDG_benchmark_executable]
```
To debug and verify the output, you can find the memory address of the `result` variable using `objdump`:
```bash
riscv64-unknown-elf-objdump -t ../build/bin/[SDG_benchmark_executable] | grep result
```
This will show the memory location of `result`, for example:
```bash
80000344 g     O .data  00000001 result
```
You can then run `spike` in debug mode to inspect the memory and verify the result:
```bash
spike -d --isa=rv32e ../build/bin/[SDG_benchmark_executable]
(spike) mem 80000344
(spike) r
(spike) mem 80000344
```
The `result` variable will start as `0xff` (-1) and should match the workload's prediction in `build/src/sample_data.h` after execution.

### Instruction trace generation

To get the instruction mix of the benchmarks, generate trace files by running:
```bash
make trace
```
This creates a `trace/` directory with trace files for each compiled benchmark.

### Work Measurement

Based on the generated trace files, we can measure the work to execute each
workload using:
```bash
python3 instruction-level/collect_ins_mix.py
```

### Memory Measurement

**Stack Usage:**

To measure the stack usage of a workload based on its instruction trace, run:
```bash
python3 instruction-level/measure-stack.py <trace-file>
```

**Static Analysis:**

The remaining volatile and non-volatile memory requirements can be determined by
analyzing the ELF descriptions of compiled programs:
```bash
riscv64-unknown-elf-readelf -a <compiled-benchmark-executable>
```
Volatile memory requirement (in addition to any stack usage) can be determined
from analyzing `.data` section size. Non-volatile memory requirements can be
determined from `.text` and `.srodata` sections. These sizes can be further
validated by the size of the `LOAD` program segment.

## Cycle-level Workflow

This workflow uses an RTL-level simulator (Icarus Verilog) for cycle-accurate simulations.
Analysis of cycle-level results can be found [here](cycle-level/CycleLevelAnalysis.ipynb).

### Compilation

To compile a benchmark for RTL simulation, use the `_serv` make targets. This will generate a `.hex` file in the `build/hex` directory. For example:
```bash
make SDG_02_serv DATA_SAMPLE_NUM=0
```

The `cycle-level/gen-hexes.sh` script can be used to generate the make commands for a random subset of the samples for each benchmark.

### `vvp` Simulation

In each `FlexiBits` processor directory (e.g. `serv`), compile the `servant_tb.v` testbench:
```bash
iverilog -o servant_sim.out -y rtl/ -y  servant/ -y serving/ -y servile/ -y bench/ ./bench/servant_tb.v
```

Test the compiled `servant_sim.out` file. Run Hello World Simulation using this command:
```
./servant_sim.out +firmware=../sw/hello_uart.hex
```
You will see the following output:
```
Preloading servant_tb.dut.dut.ram from hello_uart.hex
Loading RAM from sw/hello_uart.hex
Hi, I'm Servant!
Test complete
```

Finally, run simulation with generated `FlexiBench` hex files:
```bash
./servant_sim.out +firmware=path/to/Flexibench/build/hex/[benchmark].hex
```

The output of this simulation will be the value of the `result` variable.

The `cycle-level/gen-vcd.sh` script can be used to run simulations and generate VCD waveform files for further analysis. After generating VCDs, the `cycle-level/calc-times.py` script can be used to parse the VCDs and report simulation times.

## Kernel Ablation Workflow

The `kernel-ablation/` directory provides a case study on the Food Spoilage Detection benchmark, exploring different software kernel implementations and their impact on accuracy and performance. This study demonstrates how `FlexiBench` can be used to evaluate different software and hardware configurations for a given SDG application.

### Implementations

The C-code for each kernel implementation can be found in [`kernel-ablation/src/`](kernel-ablation/src/).

### Compiling

The `make kernel_ablation` and `make kernel_ablation_serv` targets can be used
to compile the different kernel implementations for instruction-level and
cycle-level simulation, respectively.

### Ablation Analysis
The `flexiflow/KernelAblation.ipynb` notebook provides a detailed analysis of the trade-offs between the different kernel implementations.
