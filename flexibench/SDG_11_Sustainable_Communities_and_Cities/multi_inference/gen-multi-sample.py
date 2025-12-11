import csv
import argparse

def generate_multi_header(csv_filename, header_filename, quant):
    # Default quantization value
    if quant == 0:
        quant = 8

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if quant != 8:
            print(f"Error: cannot quantize to {quant}")
            return

        if len(rows) < 2:
            print("Error: No data rows found in CSV.")
            return

        var_names = rows[0]
        data_rows = rows[1:]
        num_samples = len(data_rows)
        num_features = len(var_names) - 1  # Last column is label

        # Indices for each MQ column
        names = ["PM25","PM10","NO","NO2","NOx","NH3","CO","SO2","O3","Benzene","Toluene","Xylene"]
        label_idx = 12  # Last column

        # Prepare arrays for each MQ sensor and label
        mq_arrays = {name: [] for name in names}
        label_array = []

        for row in data_rows:
            for idx, name in enumerate(names):
                mq_arrays[name].append(row[idx])
            label_array.append(row[label_idx])

        with open(header_filename, 'w') as header_file:
            header_file.write(f"// Multi-sample data: {num_samples} samples\n")
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define NUM_SAMPLES {num_samples}\n\n")

            for name in names:
                values = ', '.join(mq_arrays[name])
                header_file.write(f"const unsigned char {name}_Vector[NUM_SAMPLES] = {{{values}}};\n")
            header_file.write(f"const char Label_Vector[NUM_SAMPLES] = {{{', '.join(label_array)}}};\n\n")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate a C header file with arrays for all samples.')
    parser.add_argument('data', help='Data CSV')
    parser.add_argument('output_header', help='Output filepath')
    parser.add_argument('quant', type=int, help='Quantization bits')

    args = parser.parse_args()

    data = args.data
    header_filename = f"{args.output_header}/sample_data.h"
    quant = args.quant

    generate_multi_header(data, header_filename, quant)
