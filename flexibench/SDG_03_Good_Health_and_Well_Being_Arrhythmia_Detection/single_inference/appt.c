#include "sample_data.h"

volatile int rpeaks_pos_fifo[3];
volatile unsigned int aclt_fifo[ACLT_FIFO_SIZE];
volatile unsigned int rpeak_hist_fifo[RPEAK_HIST_FIFO_SIZE];
volatile unsigned char rr_bin_vector[NUM_RR_BIN_ITEMS - 1]; 
volatile unsigned char drr_bin_vector[NUM_DRR_BIN_ITEMS - 1];
volatile unsigned char bloom_filter[BLOOM_FILTER_SIZE];

volatile unsigned int rpeak_hist_fifo_cnt    = 0;
volatile unsigned int peak_y                 = 0;
volatile unsigned int peak_x                 = 0;
volatile unsigned char rr_drr_ready          = 0;
volatile unsigned int rr_window_cnt          = 0;
volatile unsigned int number_of_unique_items = 0;
volatile unsigned char af_prediction         = 0;
volatile unsigned char prediction_ready      = 0;

volatile unsigned int sample_no;
volatile unsigned int th, th_init;
volatile int rr, drr;
volatile unsigned char rr_bin_num, drr_bin_num;
volatile unsigned char prev_ecg_data;
volatile unsigned char rpeak_pos_valid;
volatile char GPIO_ready = 0;
volatile char result = -1;

void update_vectors() {
   volatile unsigned char bloom_filter_hash_index;

   if (rr_drr_ready == 1) {
            if (rr_bin_vector[rr_bin_num] == 0)
                number_of_unique_items = number_of_unique_items + 1;
            else if (drr_bin_vector[drr_bin_num] == 0)
                number_of_unique_items = number_of_unique_items + 1;
            else {
                bloom_filter_hash_index = (rr_bin_num ^ drr_bin_num) >> BLOOM_FILTER_SCALE;
                if (bloom_filter[bloom_filter_hash_index] == 0)
                    number_of_unique_items = number_of_unique_items + 1;
                bloom_filter[bloom_filter_hash_index] = 1;
            }
            rr_bin_vector[rr_bin_num]   = 1;
            drr_bin_vector[drr_bin_num] = 1;

            rr_window_cnt = rr_window_cnt + 1;
  }
}

// Approximate Pair Presence Tracking (APPT) algorithm is simplified from Lian's NEC algorithm 
void appt_predict() {
  volatile unsigned char i;

  prediction_ready = 0;

  if (rr_window_cnt == RR_WINDOW_SIZE) {
            if (number_of_unique_items > NEC_THRESHOLD) af_prediction   = 1;
            else af_prediction   = 0;

            prediction_ready = 1;

            rr_window_cnt          = 0;
            number_of_unique_items = 0;

            for (i=0; i<NUM_RR_BIN_ITEMS-1; i++) rr_bin_vector[i]     = 0;
            for (i=0; i<NUM_DRR_BIN_ITEMS-1; i++) drr_bin_vector[i]   = 0;
            for (i=0; i<BLOOM_FILTER_SIZE; i++) bloom_filter[i]       = 0;
  }
}



void cal_rr_drr_bin_nums() {
    short RR_BIN_FIRST_NUM, RR_BIN_SECOND_NUM, RR_BIN_LAST_NUM, DRR_BIN_FIRST_NUM, DRR_BIN_SECOND_NUM, DRR_BIN_LAST_NUM;

    RR_BIN_FIRST_NUM    = rr_bins[0];
    RR_BIN_SECOND_NUM   = rr_bins[1];
    RR_BIN_LAST_NUM     = rr_bins[NUM_RR_BIN_ITEMS-1];

    DRR_BIN_FIRST_NUM   = drr_bins[0];
    DRR_BIN_SECOND_NUM  = drr_bins[1];
    DRR_BIN_LAST_NUM    = drr_bins[NUM_DRR_BIN_ITEMS-1];

    // Locate RR bin
    if (rr < RR_BIN_FIRST_NUM)
        rr_bin_num = 0;
    else if (rr >= RR_BIN_LAST_NUM)
        rr_bin_num = NUM_RR_BIN_ITEMS - 2;
    else
        rr_bin_num = ((rr - RR_BIN_FIRST_NUM) >> BIN_INTERVAL_BW);

    // Locate dRR bin
    if (drr < DRR_BIN_FIRST_NUM)
        drr_bin_num = 0;
    else if (drr >= DRR_BIN_LAST_NUM)
        drr_bin_num = NUM_DRR_BIN_ITEMS - 2;
    else
        drr_bin_num = ((drr - DRR_BIN_FIRST_NUM) >> BIN_INTERVAL_BW);
}

void calc_rr_drr() {
    //Only check the rpeak position fifo if it is full
    if (rpeak_hist_fifo_cnt >= 3) {
        if (rpeak_pos_valid == 1) {
            if ((rpeaks_pos_fifo[2] - rpeaks_pos_fifo[1]) > MAXRR_VALUE) {
                rr  = MAXRR_VALUE;
                if ((rpeaks_pos_fifo[1] - rpeaks_pos_fifo[0]) > MAXRR_VALUE)
                    drr = 0;
                else
                    drr = MAXRR_VALUE - (rpeaks_pos_fifo[1] - rpeaks_pos_fifo[0]);
            }
            else {
                rr  = rpeaks_pos_fifo[2] - rpeaks_pos_fifo[1];
                if ((rpeaks_pos_fifo[1] - rpeaks_pos_fifo[0]) > MAXRR_VALUE)
                    drr =  rpeaks_pos_fifo[2] - rpeaks_pos_fifo[1] - MAXRR_VALUE;
                else
                    drr = rpeaks_pos_fifo[2] - (rpeaks_pos_fifo[1] << 1) + rpeaks_pos_fifo[0];
            }
            rr_drr_ready = 1;
        }
        else {
            rr_drr_ready = 0;
            drr          = 0;
            rr           = 0;
        }
    }
    
}

int calc_aclt(volatile unsigned char curr, volatile unsigned char prev) {
    int y_d;

    y_d = curr - prev;
    // find absolute value of y_d[n]
    if (y_d < 0) y_d = -y_d;
    
    return y_d;
}

//Find the max of aclt values for 1 second of ECG data
void scan_onesecond_ecg_data() { 
    volatile unsigned int max_aclt_val, aclt_val;

    max_aclt_val = 0;
    sample_no    = 1;
    while (sample_no < SAMPLE_RATE) {
        aclt_val = calc_aclt(ecg_data[sample_no], ecg_data[sample_no-1]);
        if (aclt_val > max_aclt_val) max_aclt_val = aclt_val; 
        sample_no++;
    }

    prev_ecg_data = ecg_data[sample_no-1];

    //Make the initial threshold the half of the max value during 1 second ECG data
    th_init = max_aclt_val >> 1;
}

// The initial threashold value is calculated in the first second of the ECG data
void aclt(volatile unsigned char curr_ecg_data) {
    volatile unsigned char i;
    volatile unsigned int aclt_val;
    volatile unsigned int y_aclt;
    volatile unsigned int max_rpeak_pos;

    rpeak_pos_valid = 0;

    aclt_val = calc_aclt(curr_ecg_data, prev_ecg_data);
        
    //Add the new value to the fifo
    //The new value enters the fifo array from the first index        
    for (i=0; i<ACLT_FIFO_SIZE-1; i++)
            aclt_fifo[i] = aclt_fifo[i+1];

    aclt_fifo[ACLT_FIFO_SIZE-1] = aclt_val;

    //sum all elements in the aclt_fifo
    y_aclt = 0;
    for (i=0; i<ACLT_FIFO_SIZE; i++) y_aclt += aclt_fifo[i];

    // --- Calculate threshold ---
    if (rpeak_hist_fifo_cnt == RPEAK_HIST_FIFO_SIZE) {
            // Find maximum rpeak pos
            max_rpeak_pos = rpeak_hist_fifo[0];
            for (i=1; i<RPEAK_HIST_FIFO_SIZE; i++) {
                    if (rpeak_hist_fifo[i] > max_rpeak_pos) max_rpeak_pos = rpeak_hist_fifo[i];
            }
            th = max_rpeak_pos >> 1;;
    }
    else th = th_init;

    // --- Find Rpeaks ---
    if (y_aclt >= th) {
        if (y_aclt > peak_y) {
            peak_y = y_aclt;
            peak_x = sample_no;
        }
    }
    else {
        if (peak_y != 0) {
            //Add the new value to the fifo
            //The new value enters the fifo array from the first index 
            for (i=0; i<RPEAK_HIST_FIFO_SIZE-1; i++)
                rpeak_hist_fifo[i] = rpeak_hist_fifo[i+1];

            rpeak_hist_fifo[RPEAK_HIST_FIFO_SIZE-1] = peak_y;

            // Shift the array by 1
            //rpeak_hist_fifo = rpeak_hist_fifo[1:len(rpeak_hist_fifo)]
            for (i=0; i<2; i++)
                rpeaks_pos_fifo[i] = rpeaks_pos_fifo[i+1];
                
            rpeaks_pos_fifo[2] = peak_x;

            // Check if the fifo is full
            if (rpeak_hist_fifo_cnt >= RPEAK_HIST_FIFO_SIZE)
                rpeak_hist_fifo_cnt = RPEAK_HIST_FIFO_SIZE;
            else
                rpeak_hist_fifo_cnt = rpeak_hist_fifo_cnt + 1;
            

            rpeak_pos_valid = 1;
            peak_y          = 0;
            peak_x          = 0;
        }
    }        
    prev_ecg_data = curr_ecg_data;          
}


int Appt_RR_Detection() {
 volatile unsigned char i;
 char GPIO = -1;

 for (i=0; i<3; i++) rpeaks_pos_fifo[i]                    = -1;
 for (i=0; i<ACLT_FIFO_SIZE; i++) aclt_fifo[i]             = 0;
 for (i=0; i<RPEAK_HIST_FIFO_SIZE; i++) rpeak_hist_fifo[i] = 0;
 for (i=0; i<NUM_RR_BIN_ITEMS-1; i++) rr_bin_vector[i]     = 0;
 for (i=0; i<NUM_DRR_BIN_ITEMS-1; i++) drr_bin_vector[i]   = 0;
 for (i=0; i<BLOOM_FILTER_SIZE; i++) bloom_filter[i]       = 0;

 scan_onesecond_ecg_data();
 int inference_num = 0 ;

 // Continue from the next sample
 while (sample_no < ECG_DATA_LENGTH) {
    aclt(ecg_data[sample_no]);
    calc_rr_drr();
    cal_rr_drr_bin_nums();
    af_prediction   = 0; 
    update_vectors();
    appt_predict(); 


    if (prediction_ready == 1) {
        inference_num++;
        GPIO_ready = 1;
        GPIO = af_prediction;
    } else {
        GPIO_ready = 0;
    }

    sample_no++;
 }

 return GPIO;
}

int main() {
    result = Appt_RR_Detection();
    return 0;
}
