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

        # Check quantization
        if quant != 8:
            print(f"Error: cannot quantize to {quant}")
            return

        # Extract headers and sample row
        var_names = rows[0]  # Column names
        row = rows[sample+1]  # Data row

        # Open header file for writing
        with open(header_filename, 'w') as header_file:
            header_file.write(f"// Sample {sample}\n")
            header_file.write(f"#define QUANTIZATION {quant}\n\n")

            # Define the expected C types for each variable
            quant_types = [
                "unsigned short",     # Temperature (rounded)
                "unsigned short",     # Humidity (rounded)
                "unsigned short",     # Light
                "unsigned short",     # CO2
                "unsigned short",     # HumidityRatio
                "char",      # Occupancy
                "char"       # Python Reference
            ]

            # Skip the "date" column and write each variable
            for var in range(0, len(var_names)):  # Start from 1 to skip "date"
                var_name = var_names[var]
                value = row[var]
                
                # Write to header file
                header_file.write(f"const volatile {quant_types[var]} {var_name} = {value};\n")

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
