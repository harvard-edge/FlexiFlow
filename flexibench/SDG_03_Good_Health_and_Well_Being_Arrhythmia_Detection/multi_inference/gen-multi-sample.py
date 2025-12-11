import csv
import argparse

def generate_header(csv_filename, header_filename, quant):
    # Default quantization value
    if quant == 0:
        quant = 7

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        row = list(csv_reader)[0]

        # Determine quantization datatype
        if quant != 7:
            print(f"Error: cannot quantize to {quant}")
            return

        with open(header_filename, 'w') as header_file:
            data_range = 357769

            header_file.write("#include \"static_data.h\"\n")
            header_file.write(f"#define ECG_DATA_LENGTH {data_range}\n")
            header_file.write("""
#define SAMPLE_RATE             200 //sampling frequency in Hz
#define ACLT_FIFO_SIZE           20 
#define RPEAK_HIST_FIFO_SIZE      8
#define NEC_THRESHOLD            19
#define BLOOM_FILTER_SIZE        16
#define RR_WINDOW_SIZE           32
#define MAXRR_VALUE             255
#define BLOOM_FILTER_SCALE        2
#define NUM_RR_BIN_ITEMS         35
#define NUM_DRR_BIN_ITEMS        30
#define BIN_INTERVAL_BW           3
#define RR_BIN_BW                 6
#define DRR_BIN_BW                5

volatile const short rr_bins  [NUM_RR_BIN_ITEMS]  = {40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 256, 264, 272, 280, 288, 296, 304, 312};
volatile const short drr_bins [NUM_DRR_BIN_ITEMS] = {-60, -52, -44, -36, -28, -20, -12, -4, 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100, 108, 116, 124, 132, 140, 148, 156, 164, 172};
""")

            header_file.write("\n")
            header_file.write("volatile const unsigned char ecg_data[ECG_DATA_LENGTH] = {\n")
            for i in range(data_range):
                header_file.write(f"  {row[i]},\n")
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

