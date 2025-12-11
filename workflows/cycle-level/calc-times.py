import os
import re
import argparse
from collections import defaultdict, deque
from tqdm import tqdm  # Import tqdm for progress bars

def extract_last_timestamp(vcd_path):
    """Extracts the last simulation time from a .vcd file."""
    last_timestamp = 0
    try:
        with open(vcd_path, 'r') as f:
            for line in f:
                if line.startswith('#'):
                    try:
                        time = int(line[1:])
                        if time > last_timestamp:
                            last_timestamp = time
                    except ValueError:
                        continue
    except Exception as e:
        print(f"Error reading {vcd_path}: {e}")
    return last_timestamp

def compute_average_sim_times(results_dir):
    summary = {}
    
    # Iterate over the subdirectories with tqdm progress bar
    for subdir in ['serv', 'qerv', 'herv']:
        path = os.path.join(results_dir, subdir)
        if not os.path.isdir(path):
            print(f"Warning: {path} does not exist.")
            continue

        sdg_times = defaultdict(list)

        # Iterate over the files in the directory with tqdm progress bar
        files = [file for file in os.listdir(path) if file.endswith('.vcd')]
        for file in tqdm(files, desc=f"Processing {subdir}", unit="file"):  # Wrap file loop in tqdm
            match = re.match(r'(SDG_[^_]+)_.*\.vcd$', file)
            if match:
                sdg_prefix = match.group(1)
                full_path = os.path.join(path, file)
                sim_time = extract_last_timestamp(full_path)
                if sim_time > 0:
                    sdg_times[sdg_prefix].append(sim_time)

        # Compute averages
        avg_times = {k: sum(v)/len(v) for k, v in sdg_times.items() if v}
        summary[subdir] = avg_times

    return summary

def main():
    parser = argparse.ArgumentParser(description="Compute average VCD simulation times.")
    parser.add_argument("results_dir", help="Path to the results directory containing serv/, qerv/, herv/")
    args = parser.parse_args()

    summary = compute_average_sim_times(args.results_dir)

    # Print the results
    for subdir, sdg_data in summary.items():
        print(f"\n{subdir.upper()}:")
        for sdg, avg_time in sorted(sdg_data.items()):
            print(f"  {sdg}: {avg_time:.2f} time units")

if __name__ == "__main__":
    main()
