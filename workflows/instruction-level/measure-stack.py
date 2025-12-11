import re
import argparse
from tqdm import tqdm

def parse_trace_and_get_max_stack(filename):
    sp = 0
    min_sp = 0  # Minimum value of SP during execution (max stack usage)
    pattern = re.compile(r'addi\s+sp,\s*sp,\s*(-?\d+)', re.IGNORECASE)

    # First, count total lines for tqdm
    with open(filename, 'r') as f:
        total_lines = sum(1 for _ in f)

    with open(filename, 'r') as file:
        for line in tqdm(file, total=total_lines, desc="Processing trace"):
            match = pattern.search(line)
            if match:
                imm = int(match.group(1))
                sp += imm
                min_sp = min(min_sp, sp)

    max_stack_size = abs(min_sp)
    print(f"\nMaximum stack size used: {max_stack_size} bytes")

def main():
    parser = argparse.ArgumentParser(
        description="Measure maximum stack size from a RISC-V instruction trace."
    )
    parser.add_argument(
        "tracefile", type=str,
        help="Path to the instruction-level trace file"
    )

    args = parser.parse_args()
    parse_trace_and_get_max_stack(args.tracefile)

if __name__ == "__main__":
    main()

