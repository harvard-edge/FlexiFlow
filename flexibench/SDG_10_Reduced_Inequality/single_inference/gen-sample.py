import csv
import argparse

def generate_header(csv_filename, header_filename, sample, quant):
    # Default quantization value
    if quant == 0:
        quant = 2
    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if sample >= len(rows):
            print(f"Error: sample {sample} out of range")
            return

        if quant != 2:
            print(f"Error: cannot quantize to {quant}")
            return

        row = rows[sample]

        with open(header_filename, 'w') as header_file:

            header_file.write(f"// Sample {sample}\n")
            header_file.write(f"#include \"static_data.h\"\n")
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write("\n")

            header_file.write(f"const volatile char Golden_Reference_AM = {row[0]};\n\n")

            header_file.write("const volatile int Ngram_Array[VECTOR_SIZE] = { ")

            # Write the row values, separated by commas
            header_file.write(", ".join(row[1:]))

            header_file.write(" };")

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
