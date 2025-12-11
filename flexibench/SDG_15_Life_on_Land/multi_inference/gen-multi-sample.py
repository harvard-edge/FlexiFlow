import csv
import argparse

def generate_header(csv_filename, header_filename, quant):
    # Default quantization value
    if quant == 0:
        quant = 8

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        # Determine quantization datatype
        if quant != 8:
            print(f"Error: cannot quantize to {quant}")
            return

        with open(header_filename, 'w') as header_file:
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define Num_Data_Samples {len(rows)}\n")

            header_file.write(f"""
#define Message_Bits 8
#define Samples_Per_Symbol 1200
#define Num_Data_Points (Message_Bits * Samples_Per_Symbol)
#define Num_Degrees 360
// Output length will be the same length as input (8 bits)
#define Num_Output_Points Num_Data_Points

#define AMPLITUDE 127  // Amplitude of the sine wave
#define SAMPLE_RATE 120000  // in Hz
#define FREQUENCY_1 100  // Frequency for '1'
#define FREQUENCY_2 200  // Frequency for '0'
"""
                              )

            header_file.write("const volatile char Golden_Reference_Prediction_Vector[Num_Data_Samples] = {\n");
            for row in rows:
                header_file.write(f"    {row[0]},\n")
            header_file.write("};\n")

            header_file.write("const unsigned char Verification_Vector[Num_Data_Samples] = {\n");
            for row in rows:
                header_file.write(f"    0b{row[1]},\n")
            header_file.write("};\n")

            header_file.write("""
// Precomputed sine wave lookup table (scaled to 8-bit integer range)
volatile const int sine_wave_lookup [Num_Degrees] = {
      0,    2,    4,    6,    8,   11,   13,   15,   17,   19,
     22,   24,   26,   28,   30,   32,   35,   37,   39,   41,
     43,   45,   47,   49,   51,   53,   55,   57,   59,   61,
     63,   65,   67,   69,   71,   72,   74,   76,   78,   79,
     81,   83,   84,   86,   88,   89,   91,   92,   94,   95,
     97,   98,  100,  101,  102,  104,  105,  106,  107,  108,
    109,  111,  112,  113,  114,  115,  116,  116,  117,  118,
    119,  120,  120,  121,  122,  122,  123,  123,  124,  124,
    125,  125,  125,  126,  126,  126,  126,  126,  126,  126,
    127,  126,  126,  126,  126,  126,  126,  126,  125,  125,
    125,  124,  124,  123,  123,  122,  122,  121,  120,  120,
    119,  118,  117,  116,  116,  115,  114,  113,  112,  111,
    109,  108,  107,  106,  105,  104,  102,  101,  100,   98,
     97,   95,   94,   92,   91,   89,   88,   86,   84,   83,
     81,   79,   78,   76,   74,   72,   71,   69,   67,   65,
     63,   61,   59,   57,   55,   53,   51,   49,   47,   45,
     43,   41,   39,   37,   35,   32,   30,   28,   26,   24,
     22,   19,   17,   15,   13,   11,    8,    6,    4,    2,
      0,   -2,   -4,   -6,   -8,  -11,  -13,  -15,  -17,  -19,
    -22,  -24,  -26,  -28,  -30,  -32,  -35,  -37,  -39,  -41,
    -43,  -45,  -47,  -49,  -51,  -53,  -55,  -57,  -59,  -61,
    -63,  -65,  -67,  -69,  -71,  -72,  -74,  -76,  -78,  -79,
    -81,  -83,  -84,  -86,  -88,  -89,  -91,  -92,  -94,  -95,
    -97,  -98, -100, -101, -102, -104, -105, -106, -107, -108,
   -109, -111, -112, -113, -114, -115, -116, -116, -117, -118,
   -119, -120, -120, -121, -122, -122, -123, -123, -124, -124,
   -125, -125, -125, -126, -126, -126, -126, -126, -126, -126,
   -127, -126, -126, -126, -126, -126, -126, -126, -125, -125,
   -125, -124, -124, -123, -123, -122, -122, -121, -120, -120,
   -119, -118, -117, -116, -116, -115, -114, -113, -112, -111,
   -109, -108, -107, -106, -105, -104, -102, -101, -100,  -98,
    -97,  -95,  -94,  -92,  -91,  -89,  -88,  -86,  -84,  -83,
    -81,  -79,  -78,  -76,  -74,  -72,  -71,  -69,  -67,  -65,
    -63,  -61,  -59,  -57,  -55,  -53,  -51,  -49,  -47,  -45,
    -43,  -41,  -39,  -37,  -35,  -32,  -30,  -28,  -26,  -24,
    -22,  -19,  -17,  -15,  -13,  -11,   -8,   -6,   -4,   -2,
};
""")

            header_file.write("\n")

            header_file.write("const int RFID_Input_Signal_Vector [Num_Data_Samples][Num_Data_Points] = {\n")

            # Iterate through entire signal
            for row in rows:
                header_file.write("  {\n")
                for var in range(2, len(row)):
                    header_file.write(f"    {row[var]},\n")
                header_file.write("  },\n")
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

