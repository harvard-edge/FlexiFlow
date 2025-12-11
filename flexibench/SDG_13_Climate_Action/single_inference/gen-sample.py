import csv
import argparse

def quantize_moisture(val, quant):
    return int((float(val) - 4) / 1018 * (2**quant - 1))

def quantize_temp(val, quant):
    return int((float(val) - 10) / 35 * (2**quant - 1))

def generate_header(csv_filename, header_filename, sample, quant):
    # Default quantization value
    if quant == 0:
        quant = 8

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if quant != 8:
            print(f"Error: cannot quantize to {quant}")
            return

        training_rows = int((len(rows) - 1) * 0.8)
        data_rows = len(rows) - 1 - training_rows

        if sample >= data_rows:
            print(f"Error: sample {sample} out of range")
            return

        var_names = rows[0]
        row = rows[sample+1+training_rows]

        num_features = len(var_names) - 1
        pump_idx = 2

        with open(header_filename, 'w') as header_file:
            header_file.write(f"// Sample {sample}\n")
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define Num_Training_Samples {training_rows}\n")

            header_file.write("\n")

            # List of quantization functions to be used on the columns
            quant_functions = [quantize_moisture,quantize_temp]

            header_file.write(f"const volatile char Golden_Reference = {row[pump_idx]};\n");

            moisture = quantize_moisture(row[0], quant)
            temp = quantize_temp(row[1], quant)
            
            header_file.write(f"const volatile short Testing_Moisture = {moisture};\n")
            header_file.write(f"const volatile short Testing_Temp = {temp};\n")
            header_file.write("\n")

            header_file.write("const short Training_Moisture_Vector[Num_Training_Samples] = {\n")
            for i in range(1, training_rows+1):
                var = 0
                x = rows[i][var]
                if quant_functions[var] != None:
                    x = quant_functions[var](x,quant)
                header_file.write(f"  {x},\n")
            header_file.write("};\n\n")

            header_file.write("const short Training_Temp_Vector[Num_Training_Samples] = {\n")
            for i in range(1, training_rows+1):
                var = 1
                x = rows[i][var]
                if quant_functions[var] != None:
                    x = quant_functions[var](x,quant)
                header_file.write(f"  {x},\n")
            header_file.write("};\n\n")

            header_file.write("const char Training_Pump_Vector[Num_Training_Samples] = {\n")
            for i in range(1, training_rows+1):
                x = rows[i][pump_idx]
                header_file.write(f"  {x},\n")
            header_file.write("};\n\n")

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

