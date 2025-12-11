import csv
import argparse

#TODO: update these ranges
def quantize_O2(val, quant):
    return int(float(val) / 14.5 * (2**quant - 1))

def quantize_pH(val, quant):
    return int(float(val) / 14 * (2**quant - 1))

def quantize_TDS(val, quant):
    return int(float(val) / 55600 * (2**quant - 1))

def generate_header(csv_filename, header_filename, quant):
    # Default quantization value
    if quant == 0:
        quant = 16

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if quant > 16 or quant < 1:
            print(f"Error: cannot quantize to {quant}")
            return

        var_names = rows[0]

        with open(header_filename, 'w') as header_file:
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define Num_Data_Samples {len(rows)-1}\n")

            min_o2 = quantize_O2(6, quant)
            header_file.write(f"#define O2_MIN {min_o2}\n")
            min_ph = quantize_pH(6.5, quant)
            header_file.write(f"#define PH_MIN {min_ph}\n")
            max_ph = quantize_pH(8.5, quant)
            header_file.write(f"#define PH_MAX {max_ph}\n")
            max_tds = quantize_TDS(600, quant)
            header_file.write(f"#define TDS_MAX {max_tds}\n")

            header_file.write("\n")

            # List of quantization functions to be used on the columns
            quant_functions = [quantize_O2,quantize_pH,quantize_TDS,None]

            # Iterate through all variables, quantize if needed, and write out
            for var in range(len(var_names)):
                header_file.write(f"const volatile long {var_names[var]}_Vector[Num_Data_Samples] = {{\n")
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

