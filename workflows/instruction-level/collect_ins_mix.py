import os
import re
import matplotlib.pyplot as plt
from collections import defaultdict, Counter

plt.rcParams.update({
    'font.size': 16,           # Base font size
    'axes.titlesize': 16,      # Title font
    'axes.labelsize': 16,      # Axis label font
    'xtick.labelsize': 16,     # X tick labels
    'ytick.labelsize': 16,     # Y tick labels
    'legend.fontsize': 16,     # Legend font
    'figure.titlesize': 16     # Overall figure title (if used)
})

# Directory containing the trace files
directory_path = '../trace/'

# Regular expression patterns for different types of instructions
branches = re.compile(r'\b(beq|bne|blt|bge|bltu|bgeu|bnez|beqz|bltz|bgez)\b')
jumps = re.compile(r'jal|j|jr|ret')
loads = re.compile(r'\b(lb|lh|lw|ld|lbu|lhu|lwu)\b')
stores = re.compile(r'\b(sb|sh|sw|sd|sc.w|sc.d)\b')
i_types = re.compile(r'addi|xori|andi|ori|auipc|li|lui|not')
r_types = re.compile(r'add|sub|xor|and|or|mv|csrr')
shifts_slts = re.compile(r'srai|slli|srli|sra|sll|srl|slt|sltu|slti|sltiu|snez')

name_dir = {
            "SDG_02": "07. Food Spoilage Detection\n(Logistic Regression)",
            "SDG_03_arrhythmia": "06. Arrhythmia Detection\n(Bloom Filter)",
            "SDG_03_cardiotocography": "08. Cardiotocography\n(MLP)",
            "SDG_06": "03. Water Quality Monitoring\n(Threshold)",
            "SDG_07": "04. HVAC Control\n(Random Forest)",
            "SDG_09": "09. Package Tracking\n(MLP)",
            "SDG_10": "01. Gesture Recognition\n(Binary Cosine Similarity)",
            "SDG_11": "05. Air Pollution Monitoring\n(XGBoost)",
            "SDG_12": "02. Malodor Classification\n(Decision Tree)",
            "SDG_13": "10. Smart Irrigation Control\n(KNN)",
            "SDG_15": "11. Tree Tracking\n(Discrete Fourier Transform)"
        }

# Define cycles per instruction type
cycles_per_instruction = {
    'Others': 4+3+4+3,
    'I-types': 4+3,
    'Loads': 4+3+4+3+70,  # Assuming 70 cycle latency for mem read
    'R-types': 4+3,
    'Stores': 4+3+4+3+35,  # Assuming 35 cycle latency for mem write
    'Branches': 4+3+4+3,
    'Shifts and SLTs': 4+3+4+3,
    'Jumps': 4+3
}

# Define cycles per instruction type
cycles_per_instruction_by_core = {
    "HERV":{
        'Others': 4+3+4+3,
        'I-types': 4+3,
        'Loads': 4+3+4+3+70,  # Assuming 70 cycle latency for mem read
        'R-types': 4+3,
        'Stores': 4+3+4+3+35,  # Assuming 35 cycle latency for mem write
        'Branches': 4+3+4+3,
        'Shifts and SLTs': 4+3+4+3,
        'Jumps': 4+3
    },
    "QERV":{
        'Others': 8+3+8+3,
        'I-types': 8+3,
        'Loads': 8+3+8+3+70,  # Assuming 70 cycle latency for mem read
        'R-types': 8+3,
        'Stores': 8+3+8+3+35,  # Assuming 35 cycle latency for mem write
        'Branches': 8+3+8+3,
        'Shifts and SLTs': 8+3+8+3,
        'Jumps': 8+3
    },
    "SERV":{
        'Others': 32+3+32+3,
        'I-types': 32+3,
        'Loads': 32+3+32+3+70,  # Assuming 70 cycle latency for mem read
        'R-types': 32+3,
        'Stores': 32+3+32+3+35,  # Assuming 35 cycle latency for mem write
        'Branches': 32+3+32+3,
        'Shifts and SLTs': 32+3+32+3,
        'Jumps': 32+3
    }
}

# Function to classify instructions
def classify_instruction(instruction):
    if branches.match(instruction):
        return 'Branches'
    elif loads.match(instruction):
        return 'Loads'
    elif stores.match(instruction):
        return 'Stores'
    elif i_types.match(instruction):
    	return 'I-types'
    elif r_types.match(instruction):
    	return 'R-types'
    elif shifts_slts.match(instruction):
    	return 'Shifts and SLTs'
    elif jumps.match(instruction):
        return 'Jumps'
    else:
        return 'Others'

# Parse the spike output file
def parse_spike_output(file_path):
    instruction_counts = defaultdict(int)
    other_instructions = Counter()
    skip = 1
    
    with open(file_path, 'r') as file:
        for line in file:
            if skip: # Skip error message from spike
                skip = 0
                continue
            # Match the instruction mnemonic part of the trace line
            match = re.search(r'\)\s(c\.)?(\S+)', line)
            if match:
                instruction = match.group(2)
                category = classify_instruction(instruction)
                instruction_counts[category] += 1
                if category == 'Others':
                    other_instructions[instruction] += 1
    
    total_instructions = sum(instruction_counts.values())
    
    return instruction_counts, total_instructions, other_instructions

# Plotting function for instruction mix
def plot_instruction_mix(instruction_data, total_instructions_data):
    # Sort workloads by their name
    sorted_workloads = sorted(instruction_data.keys())

    # Define pastel colors
    colors = ['#92c6ff', '#97f0aa', '#f4b400', '#d291bc', '#ff4500', '#764428', '#ff55a3']  # Light blue, green, yellow, pink

    # Create the stacked bar chart
    fig, ax = plt.subplots(figsize=(16, 14))  


    # Initialize the bottom for the stacking
    bottom = [0] * len(sorted_workloads)
    
    for category, color in zip(['Branches', 'Loads', 'Stores', 'I-types', 'R-types', 'Shifts and SLTs', 'Jumps'], colors):
        values = [(instruction_data[workload][category] / total_instructions_data[workload]) * 100 for workload in sorted_workloads]
        bars = ax.bar(sorted_workloads, values, label=category, color=color, bottom=bottom)
        for bar, value in zip(bars, values):
            if value > 0:
                height = bar.get_height()
                ax.text(
                    bar.get_x() + bar.get_width() / 2, 
                    bar.get_y() + height / 2, 
                    f'{value:.1f}%', 
                    ha='center', 
                    va='center',
                    fontsize=12,
                    
                )
        bottom = [l + v for l, v in zip(bottom, values)]

    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.set_ylabel('Percentage')
    # ax.set_title('Instruction Mix of Workloads')
    ax.legend(
        loc='lower center',
        bbox_to_anchor=(0.5, 1.05),
        ncol=7,  # Adjust depending on number of legend items
        frameon=False,
        fontsize=12
    )

    x_labels_cleaned = [re.sub(r'^\d+\.\s*', '', w) for w in sorted_workloads]
    ax.set_xticks(list(range(len(sorted_workloads))))
    ax.set_xticklabels(x_labels_cleaned, rotation=45, ha='right')


    plt.xticks(rotation=45, ha='right')  # Rotates x-axis labels and aligns them to the right
    plt.subplots_adjust(
        top=0.80,
        bottom=0.50,
        left=0.10,
        right=0.80
    )
    plt.savefig("plots/instruction_mix.png", dpi=300, bbox_inches='tight')  # High resolution and better layout
    plt.show()


# Plotting function for total instructions
def plot_total_instructions(total_instructions_data):
    # Sort workloads by their name
    sorted_workloads = sorted(total_instructions_data.keys())

    # Prepare data for the bar chart
    total_instructions = [total_instructions_data[workload] for workload in sorted_workloads]

    # Plot
    plt.figure(figsize=(16, 14))
    bars = plt.bar(sorted_workloads, total_instructions, color='#add8e6')  # Light blue color
    plt.xlabel('Workload')
    plt.ylabel('Total Instructions')
    plt.title('Total Instruction Count of Workloads')
    plt.xticks(rotation=45, ha='right')  # Rotates x-axis labels and aligns them to the right
    plt.tight_layout()
    plt.savefig("plots/total_instructions.png", dpi=300, bbox_inches='tight')  # High resolution and better layout

    outlier_index = 9 # tree tracking
    for i, bar in enumerate(bars):
        height = bar.get_height()
        label_value = total_instructions[i]

        # Place actual value above the capped bar
        if i == outlier_index:
            plt.text(bar.get_x() + bar.get_width() / 2, height + 3, f'{label_value}', ha='center', va='bottom', fontsize=10, fontweight='bold')
        else:
            plt.text(bar.get_x() + bar.get_width() / 2, height + 1, f'{label_value}', ha='center', va='bottom', fontsize=9)
    plt.yscale("log")

    plt.show()


# Plotting function to plot the number of cycles per instruction based on the instruction mix counts
# Ins	Cycles
# Others:	50
# I-types:	35
# Loads:	70
# R-types:	35
# Stores:	70
# Branches:	70
# Shifts and SLTs	70
# Plot a stacked bar for each workload where each bar's height is equal to total number of cycles and each segment of the bar should be colored for the cycles attributed each instruction type
def plot_total_cycles_per_instruction(instruction_data, total_instructions_data, log_scale=True, clock_freq=50000):
    # Sort workloads by their name
    sorted_workloads = sorted(instruction_data.keys())

    # Define pastel colors
    colors = ['orange', 'orange', 'orange', 'orange', 'orange', 'orange', 'orange']  # Light blue, green, yellow, pink

    # Create the stacked bar chart
    fig, ax = plt.subplots(figsize=(16, 14))

    # Initialize the bottom for the stacking
    bottom = [0] * len(sorted_workloads)
    
    total_cycles_per_workload = {workload: sum(instruction_data[workload][cat] * cycles_per_instruction[cat] for cat in cycles_per_instruction) for workload in sorted_workloads}

    for category, color in zip(['Branches', 'Loads', 'Stores', 'I-types', 'R-types', 'Shifts and SLTs', 'Jumps'], colors):
        values = [(instruction_data[workload][category] * cycles_per_instruction[category]) for workload in sorted_workloads]
        bars = ax.bar(sorted_workloads, values, label=category, color=color, bottom=bottom)
        bottom = [l + v for l, v in zip(bottom, values)]

    # Label the top of each bar with the total cycles and runtime in seconds
    for i, workload in enumerate(sorted_workloads):
        total_cycles = total_cycles_per_workload[workload]
        runtime_seconds = total_cycles / clock_freq
        ax.text(i, total_cycles + 0.05 * total_cycles, f'{total_cycles:.0f} cycles\n{runtime_seconds:.2f} s', ha='center', va='bottom', fontsize=12, fontweight='bold')

    # Set y-axis to log scale if log_scale is True
    if log_scale:
        ax.set_yscale('log')

    ax.set_ylabel('Total Cycles')
    ax.set_title('Total Cycles Per Instruction of Workloads')
    # ax.legend(loc='upper right', bbox_to_anchor=(1.15, 1))  # Moves legend outside the plot
    ax.set_ylim(1,1e12)

    plt.xticks(rotation=45, ha='right')  # Rotates x-axis labels and aligns them to the right
    plt.tight_layout()
    plt.savefig("plots/total_cycles_per_instruction.png", dpi=300, bbox_inches='tight')  # High resolution and better layout
    plt.show()



# Plotting function to plot the instruction mix based on cycles per instruction and instruction counts
def plot_instruction_mix_by_cycles(instruction_data, total_instructions_data):
    # Sort workloads by their name
    sorted_workloads = sorted(instruction_data.keys())

    # Define pastel colors
    colors = ['#92c6ff', '#97f0aa', '#f4b400', '#d291bc', '#ff4500', '#764428', '#ff55a3']  # Light blue, green, yellow, pink

    # Create the stacked bar chart
    fig, ax = plt.subplots(figsize=(16, 12))

    # Initialize the bottom for the stacking
    bottom = [0] * len(sorted_workloads)
    
    for category, color in zip(['Branches', 'Loads', 'Stores', 'I-types', 'R-types', 'Shifts and SLTs', 'Jumps'], colors):
        values = [(instruction_data[workload][category] * cycles_per_instruction[category]) for workload in sorted_workloads]
        total_cycles_per_workload = [sum(instruction_data[workload][cat] * cycles_per_instruction[cat] for cat in cycles_per_instruction) for workload in sorted_workloads]
        percentage_values = [value / total * 100 if total != 0 else 0 for value, total in zip(values, total_cycles_per_workload)]
        bars = ax.bar(sorted_workloads, percentage_values, label=category, color=color, bottom=bottom)
        for bar, value in zip(bars, percentage_values):
            if value > 0:
                height = bar.get_height()
                ax.text(
                    bar.get_x() + bar.get_width() / 2, 
                    bar.get_y() + height / 2, 
                    f'{value:.1f}%', 
                    ha='center', 
                    va='center',
                    fontsize=12,
                    fontweight='bold'
                )
        bottom = [l + v for l, v in zip(bottom, percentage_values)]

    ax.set_ylabel('Percentage of Cycles')
    ax.set_title('Instruction Mix by Cycles of Workloads')
    ax.legend(loc='upper right', bbox_to_anchor=(1.25, 1))  # Moves legend outside the plot
    ax.set_ylim(0,105)

    plt.xticks(rotation=45, ha='right')  # Rotates x-axis labels and aligns them to the right
    plt.tight_layout()
    plt.savefig("plots/instruction_mix_by_cycles.png", dpi=300, bbox_inches='tight')  # High resolution and better layout
    plt.show()


def plot_runtime_per_core(instruction_data, clock_freq=50000, log_scale=True):
    import matplotlib.pyplot as plt
    import re

    sorted_workloads = sorted(instruction_data.keys())
    cores = ["SERV", "QERV", "HERV"]
    colors = ['#4c72b0', '#dd8452', '#55a868']
    width = 0.25

    # Compute runtime
    runtime_data = {core: [] for core in cores}
    for workload in sorted_workloads:
        for core in cores:
            total_cycles = 0
            for category in cycles_per_instruction_by_core[core]:
                count = instruction_data[workload].get(category, 0)
                cycles = cycles_per_instruction_by_core[core][category]
                total_cycles += count * cycles
            runtime_seconds = total_cycles / clock_freq
            runtime_data[core].append(runtime_seconds)

    # Plotting
    fig, ax = plt.subplots(figsize=(16, 10))
    for i, core in enumerate(cores):
        x_positions = [j + (i - 1) * width for j in range(len(sorted_workloads))]
        ax.bar(x_positions, runtime_data[core], width, label=core, color=colors[i])

    # Axes
    ax.set_ylabel("Runtime (seconds)")

    # Clean up axis box
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    # Set log scale if specified
    if log_scale:
        ax.set_yscale('log')

    # Tick labels
    x_labels_cleaned = [re.sub(r'^\d+\.\s*', '', w) for w in sorted_workloads]
    ax.set_xticks(list(range(len(sorted_workloads))))
    ax.set_xticklabels(x_labels_cleaned, rotation=45, ha='right')

    # Add reference lines for runtime thresholds
    duty_cycle_thresholds = {
        "1 ms": 1e-3,
        "1 s": 1,
        "1 min": 60,
        "1 hr": 3600,
        "1 day": 86400,
        "1 week": 604800,
        "1 month": 2592000
    }

    for label, value in duty_cycle_thresholds.items():
        ax.axhline(y=value, linestyle='--', color='gray', linewidth=1)
        ax.text(len(sorted_workloads)-0.5, value, f" {label}", va='bottom', ha='left', color='gray', fontsize=10)

    ax.legend(
        loc='lower center',
        bbox_to_anchor=(0.5, 1.05),
        ncol=3,  # Adjust depending on number of legend items
        frameon=False,
        fontsize=12
    )
    ax.grid(axis='y', linestyle='', alpha=0.6)
    plt.subplots_adjust(
        top=0.9,
        bottom=0.40,
        left=0.15,
        right=0.95
    )
    plt.savefig("plots/flexibits_runtime_comparison.png", dpi=300)
    plt.show()


# Main function to process all trace files and plot the instruction mix
def process_trace_files(directory_path):
    instruction_data = defaultdict(lambda: defaultdict(int))
    total_instructions_data = defaultdict(int)
    all_other_instructions = defaultdict(Counter)

    for filename in os.listdir(directory_path):
        if filename.endswith('.tr'):
            file_path = os.path.join(directory_path, filename)
            workload_name = filename.replace('.tr', '')
            friendly_name = next((v for k, v in name_dir.items() if k in workload_name), workload_name)

            instruction_counts, total_instructions, other_instructions = parse_spike_output(file_path)
            other_instructions_count = sum(other_instructions.values())

            total_instructions_data[friendly_name] = total_instructions
            for category, count in instruction_counts.items():
                instruction_data[friendly_name][category] = count
            all_other_instructions[friendly_name] = other_instructions

            if total_instructions > 0:
                # Print the instruction mix and total number of instructions
                print(f'Workload: {workload_name}')
                print(f'Total Number of Instructions: {total_instructions}')
                print('Instruction Mix:')
                for category, count in instruction_counts.items():
                    print(f'{category}: {100 * count / total_instructions:.2f}%;  count: {count}')
                print(f'Others: {100* other_instructions_count / total_instructions:.2f}%;  count : {other_instructions_count}')
                # print('Unique Instructions in "Others":')
                # for inst, count in other_instructions.items():
                #    print(f'{inst}: {count}')\
                print('______________________')
            else:
                print(f'No instructions found in file: {filename}')
    
    # Manually add in tree tracking
    tree_instruction_counts = {
        'I-types': 268315600,
        'Loads': 123756000,  # Assuming 70 cycle latency for mem read
        'R-types': 883490100,
        'Stores': 85096600,  # Assuming 35 cycle latency for mem write
        'Branches': 802534300,
        'Shifts and SLTs': 897548100,
        'Jumps': 84845600
    }
    tree_total_instructions = 3145586300
    tree_other_instructions = 0
    workload_name = "SDG_15_tree_tracking_single_inference_sample_0"
    friendly_name = next((v for k, v in name_dir.items() if k in workload_name), workload_name)

    total_instructions_data[friendly_name] = tree_total_instructions
    for category, count in tree_instruction_counts.items():
        instruction_data[friendly_name][category] = count
    all_other_instructions[friendly_name] = tree_other_instructions


    # Once all files are processed, plot the instruction mix and total instructions
    #os.makedirs("plots", exist_ok=True)
    #plot_instruction_mix(instruction_data, total_instructions_data)
    #plot_total_instructions(total_instructions_data)
    #plot_total_cycles_per_instruction(instruction_data, total_instructions_data)
    #plot_instruction_mix_by_cycles(instruction_data, total_instructions_data)
    #plot_runtime_per_core(instruction_data)


# Run the processing function
if __name__ == '__main__':
    process_trace_files(directory_path)

