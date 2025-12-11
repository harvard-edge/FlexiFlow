import csv
import argparse

def generate_header(csv_filename, header_filename, sample, quant):
    # Default quantization value
    if quant == 0:
        quant = 8

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if sample >= len(rows)-1:
            print(f"Error: sample {sample} out of range")
            return

        if quant != 8:
            print(f"Error: MLP only supports 8 bit quantization currently. Cannot quantize to {quant}.")
            return

        var_names = rows[0]
        row = rows[sample+1]

        with open(header_filename, 'w') as header_file:
            header_file.write(f"// Sample {sample}\n")
            header_file.write(f"#define QUANTIZATION {quant}\n")

            header_file.write("\n")

            # Iterate through all variables and write out int8 data inputs for this workload
            for var in range(len(var_names)):
                x = row[var]
                header_file.write(f"const volatile signed char {var_names[var]} = {x};\n")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate a C header file from a CSV row.')
    parser.add_argument('data', help='Data CSV')
    parser.add_argument('output_header', help='Output filepath')
    parser.add_argument('sample', type=int, help='Sample index')
    parser.add_argument('quant', type=int, help='Quantization bits')

    args = parser.parse_args()

    data = args.data
    header_filename = f"{args.output_header}/sample_data.h"
    sample = args.sample
    quant = args.quant

    generate_header(data, header_filename, sample, quant)

