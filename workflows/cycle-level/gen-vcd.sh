#!/bin/bash

# Check if all required arguments are provided
if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]; then
    echo "Usage: $0 <firmware_folder> <vcd_folder> <servant_sim.out_path>"
    exit 1
fi

# Assign the arguments to variables
firmware_folder="$1"
vcd_folder="$2"
servant_sim_path="$3"

# Check if the firmware folder exists
if [ ! -d "$firmware_folder" ]; then
    echo "Error: Firmware folder '$firmware_folder' does not exist."
    exit 1
fi

# Check if the VCD folder exists, if not, create it
if [ ! -d "$vcd_folder" ]; then
    echo "VCD folder '$vcd_folder' does not exist. Creating it now."
    mkdir -p "$vcd_folder"
fi

# Check if the servant_sim.out file exists
if [ ! -f "$servant_sim_path" ]; then
    echo "Error: servant_sim.out file '$servant_sim_path' does not exist."
    exit 1
fi

# Loop through each firmware file in the firmware folder
for firmware in "$firmware_folder"/*.hex; do
    # Check if the file is a regular file
    if [ -f "$firmware" ]; then
        # Extract the filename without the extension
        firmware_name=$(basename "$firmware")
        vcd_file="${firmware_name%.*}.vcd"

        # Run the command with the firmware, VCD output folder, and servant_sim.out path
        "$servant_sim_path" +firmware="$firmware" +vcd="$vcd_folder/$vcd_file" &
    fi
done

