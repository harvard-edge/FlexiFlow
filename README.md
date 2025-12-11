# Lifetime-aware Design for Item-Level Intelligence
## Overview: FlexiBench, FlexiBits, & FlexiFlow 

This repository contains a full-stack, open-source framework for designing and analyzing systems that enable item-level intelligence (ILI) by embedding computation directly into disposable, low-cost items like food packaging, textiles, and medical patches.

Many ILI applications represent **computing *for* sustainability** where computing directly improves sustainability outcomes (e.g., food waste reduction, health access, water conservation). Specifically, ILI presents a unique opportunity to help make progress towards the [United Nations Sustainable Development Goals](https://sdgs.un.org/goals) (UN SDGs).

While ILI opens new avenues for computing to directly support sustainability, it also introduces a distinct set of constraints not addressed by traditional system design. Conventional silicon-based systems are prohibitively expensive, both in terms of dollar cost and environmental impact, when scaled to trillions of low-cost, disposable products. To meet these constraints, our framework targets **flexible electronics**, an emerging technology that enables ultra-low-cost, physically conformable devices with drastically reduced embodied carbon. However, these benefits come with severe limitations as flexible electronics are currently limited to kilohertz clock speeds and support only thousands of gates.

Moreover, environmental impact becomes a first-order concern at ILI scale. With deployments reaching trillions of units, even small inefficiencies in system design can accumulate massive carbon footprints. [Jevons' paradox](https://www.sciencedirect.com/science/article/pii/S0921800905001084?casa_token=GKhR4Fr7TeMAAAAA:_se9ymzPJtdgDEwh250lnxzMvkxi53SzVfF2ialbQqMwQ_WXsUMMbBp2moyKndKKEfp_ZEfqK-o) further warns that gains in efficiency can lead to higher overall consumption, underscoring the need for design frameworks that consider both embodied and operational carbon footprints. Furthermore, ILI workloads exhibit extremely heterogeneous lifetimes (1000x variation), which suggests that a one-size-fits-all hardware approach is suboptimal.

To address these challenges, our stack includes:

- **FlexiBench**: A suite of 11 real-world benchmarks aligned with the UN SDGs, capturing the diversity of workloads relevant for ILI (e.g., spoilage detection, fetal health monitoring, smart irrigation). 
  
- **FlexiBits**: A family of open-source, bit-serial RISC-V microprocessors (1-bit, 4-bit, 8-bit) optimized for extreme-area-constrained technologies like flexible electronics.

- **FlexiFlow**: A lifetime-aware design model that guides architecture selection based on expected application lifetime to minimize total carbon footprint.

## Table of Contents
- [Installation](#installation)
  - [RISC-V GNU Toolchain](#risc-v-gnu-toolchain)
  - [RISC-V Instruction Set Simulator (`spike`)](#risc-v-instruction-set-simulator-spike)
  - [RTL-level Simulation (Icarus Verilog)](#rtl-level-simulation-icarus-verilog)
- [Workflows](#workflows)
- [`FlexiBench` Benchmarks](#flexibench-benchmarks)
- [`FlexiBits` Implementations](#flexibits-implementations)
- [`FlexiFlow` Modeling](#flexiflow-modeling)
- [References](#references)

## Installation

### RISC-V GNU Toolchain

For program compilation, ELF header analysis, and hexfile generation, install
the RISC-V GNU Toolchain by following the instructions from
<https://github.com/riscv-collab/riscv-gnu-toolchain>.

### RISC-V Instruction Set Simulator (`spike`)

For instruction-level tracing and simulation necessary for memory profiling,
work measurement, and instruction mix analysis, install the RISC-V `spike`
instruction set simulator from
<https://github.com/riscv-software-src/riscv-isa-sim>.

### RTL-level Simulation (Icarus Verilog)

Finally, install Icarus Verilog for RTL-level simulation of our `FlexiBits`
cores:

```bash
sudo apt-get install iverilog
```

## Workflows

The core simulation and analysis workflows are located in the
[`workflows/`](./workflows) directory. Please refer to the
[`workflows/README.md`](./workflows/README.md) for detailed instructions on the
following:

- **Instruction-level Workflow**: For compiling benchmarks and running them on the `spike` ISA simulator to generate instruction traces for analysis.
- **Cycle-level Workflow**: For running cycle-accurate RTL-level simulations using Icarus Verilog.
- **Kernel Ablation Workflow**: A case study on the Food Spoilage Detection benchmark to explore trade-offs between different software kernel implementations.

## `FlexiBench` Benchmarks

The FlexiBench benchmarks are described in detail in the [`flexibench`](./flexibench) folder.

## `FlexiBits` Implementations

The RTL implementations of our area-optimized family of cores is shown in
[`flexibits/`](./flexibits). The three cores presented are SERV, a 1-bit
datapath core; QERV, a 4-bit datapath core; and HERV, an 8-bit datapath core.

## `FlexiFlow` Modeling

Our final `FlexiFlow` model is presented in
[`flexiflow/LifetimeModel.ipynb`](./flexiflow/LifetimeModel.ipynb). This
notebook provides the framework for exploring the trade-offs between embodied
and operational carbon footprint based on workload lifetime.
