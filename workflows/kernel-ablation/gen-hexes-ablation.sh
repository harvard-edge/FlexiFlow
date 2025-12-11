#!/bin/bash

# Function to generate random sample indices
generate_sample_indices() {
    local total_samples=$1
    local sdg_name=$2
    local limit=$((total_samples < 20 ? total_samples : 20))

    # If there are fewer than 20 samples, loop over all samples
    if [ "$total_samples" -le 20 ]; then
	    for i in $(seq 0 $((total_samples - 1))); do
            echo "make ${sdg_name}_serv DATA_SAMPLE_NUM=${i}"
        done
    else
        # Generate 20 random indices
        declare -A seen
        count=0
        while [ $count -lt $limit ]; do
            idx=$((RANDOM % total_samples))
            if [[ ! ${seen[$idx]} ]]; then
                seen[$idx]=1
                echo "make ${sdg_name}_serv DATA_SAMPLE_NUM=${idx}"
                ((count++))
            fi
        done
    fi
}

# SDG sample data
declare -A sdgs
sdgs[kernel_ablation]=555

# Generate make commands for each SDG
for sdg in "${!sdgs[@]}"; do
    sample_count=${sdgs[$sdg]}
    generate_sample_indices $sample_count $sdg
done

