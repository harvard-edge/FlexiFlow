import csv
import argparse

def generate_header(csv_filename, header_filename, quant):
    # Default quantization value
    if quant == 0:
        quant = 2
    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if quant != 2:
            print(f"Error: cannot quantize to {quant}")
            return

        with open(header_filename, 'w') as header_file:

            header_file.write(f"#include \"static_data.h\"\n")
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define Num_Data_Samples {len(rows)}\n")
            header_file.write("\n")

            header_file.write("const volatile char Golden_Reference_AM_Vector[Num_Data_Samples] = {\n")
            for row in rows:
                header_file.write(f"  {row[0]},\n")
            header_file.write("};\n\n")


            header_file.write("const volatile int Ngram_Array_Vector[Num_Data_Samples][VECTOR_SIZE] = {\n")

            # Write the row values, separated by commas
            for row in rows:
                header_file.write("{")
                header_file.write(", ".join(row[1:]))
                header_file.write("},\n")

            header_file.write("};\n")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate a C header file from a CSV row.')
    parser.add_argument('data', help='Data CSV')
    parser.add_argument('output_header', help='Output filepath')
    parser.add_argument('quant', type=int, help='Quantization bits')

    args = parser.parse_args()

    data = args.data
    header_filename = f"{args.output_header}/sample_data.h"
    quant = args.quant

    generate_header(data, header_filename, quant)
