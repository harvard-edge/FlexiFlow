import csv
import argparse

range_dict = {0: 3848, 1: 7443, 2: 10836, 3: 13911, 4: 17001, 5: 20356, 6: 23956, 7: 27436, 8: 31186, 9: 34825,
    10: 38492, 11: 42082, 12: 45698, 13: 49183, 14: 52815, 15: 56479, 16: 60157, 17: 64591, 18: 68355, 19: 72215,
    20: 75919, 21: 79609, 22: 83344, 23: 86913, 24: 90385, 25: 94124, 26: 97766, 27: 101550, 28: 105256, 29: 109064,
    30: 112814, 31: 116642, 32: 120458, 33: 124149, 34: 127949, 35: 131629, 36: 135277, 37: 138836, 38: 142638, 39: 145700,
    40: 149501, 41: 153287, 42: 156691, 43: 160395, 44: 163854, 45: 167454, 46: 171078, 47: 174846, 48: 178599, 49: 182329,
    50: 185644, 51: 189045, 52: 192552, 53: 195980, 54: 199592, 55: 203341, 56: 207013, 57: 210714, 58: 214141, 59: 217762,
    60: 221216, 61: 224827, 62: 228398, 63: 232005, 64: 235745, 65: 239152, 66: 242503, 67: 246261, 68: 249898, 69: 253613,
    70: 257470, 71: 261252, 72: 265037, 73: 268483, 74: 272229, 75: 275804, 76: 279295, 77: 282965, 78: 286763, 79: 290454,
    80: 294268, 81: 298161, 82: 301934, 83: 305690, 84: 309085, 85: 312917, 86: 316494, 87: 320248, 88: 323992, 89: 327790,
    90: 331590, 91: 335383, 92: 339252, 93: 342976, 94: 346760, 95: 350505, 96: 354269, 97: 357769}

def generate_header(csv_filename, header_filename, sample, quant):
    # Default quantization value
    if quant == 0:
        quant = 7

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        row = list(csv_reader)[0]

        if sample >= 98:
            print(f"Error: sample {sample} out of range")
            return

        # Determine quantization datatype
        if quant != 7:
            print(f"Error: cannot quantize to {quant}")
            return

        with open(header_filename, 'w') as header_file:
            data_range = range_dict[sample]

            header_file.write(f"// Sample {sample}\n")
            header_file.write(f"#define ECG_DATA_LENGTH {data_range}\n")
            header_file.write(f"#define NUM_SW_PREDICTED_LABELS {sample+1}\n")
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
    parser.add_argument('sample', type=int, help='Sample index')
    parser.add_argument('quant', type=int, help='Quantization bits')

    args = parser.parse_args()

    data = args.data
    header_filename = f"{args.output_header}/sample_data.h"
    sample = args.sample
    quant = args.quant

    generate_header(data, header_filename, sample, quant)

