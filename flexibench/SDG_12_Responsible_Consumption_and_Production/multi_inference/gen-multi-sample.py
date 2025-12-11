import csv
import argparse

#TODO: update these ranges
def quantize_sensor(val, quant):
    shift = 7 - quant # Started with 7-bit data
    return int(val) >> shift

def generate_header(csv_filename, header_filename, quant):
    # Default quantization value
    if quant == 0:
        quant = 7

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if quant != 7:
            print(f"Error: cannot quantize to {quant}")
            return

        var_names = rows[0]

        with open(header_filename, 'w') as header_file:
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define SHIFT_AMT {7-quant}\n")
            header_file.write(f"#define Num_Data_Samples {len(rows)-1}\n")

            header_file.write("\n")

            # List of quantization functions to be used on the columns
            quant_functions = [None,None,quantize_sensor,quantize_sensor,quantize_sensor,quantize_sensor,quantize_sensor,quantize_sensor,None,None]

            # Iterate through all variables, quantize if needed, and write out
            for var in range(len(var_names)):
                header_file.write(f"const volatile char {var_names[var]}_Vector[Num_Data_Samples] = {{\n")
                for i in range(1, len(rows)):
                    x = rows[i][var]
                    if quant_functions[var] != None:
                        x = quant_functions[var](x,quant)
                    header_file.write(f"  {x},\n")
                header_file.write("};\n\n")

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

