##############################################
#   Flexibench / Sustainabench Makefile      #
##############################################
# RISC-V Toolchain and Compiler
RV_PREFIX = /opt/riscv/bin/riscv64-unknown-elf-
CC = $(RV_PREFIX)gcc

# Flags telling GCC to compile to rv32e, without libraries (e.g. baremetal), to use a different memory model so that we can put our code at 0x80000000, to use the specified linker script, and turn on full optimizations.
CCFLAGS = -march=rv32e_zicsr -mabi=ilp32e -nostdlib -mcmodel=medany -Tinstruction-level/link.ld -fno-builtin -O3
CCFLAGS_SERV = -nostartfiles -march=rv32e_zicsr -mabi=ilp32e -nostdlib -mcmodel=medany -Tcycle-level/link-serv.ld -fno-builtin -O3


# Python installation
PYTHON = python3

# Source directory
SRC_DIR = ../flexibench
ABLATION_SRC = kernel-ablation/src

# Path to write compiled executables and object files
BUILD_DIR = ../build/
BUILD_BIN_DIR = $(BUILD_DIR)bin
BUILD_OBJ_DIR = $(BUILD_DIR)obj
BUILD_SRC_DIR = $(BUILD_DIR)src
BUILD_HEX_DIR = $(BUILD_DIR)hex
BUILT_FILES := $(wildcard $(BUILD_BIN_DIR)/*)

TRACE_DIR ?= ../trace/

# Default values for INFERENCE (multi or single), DATA_SAMPLE_NUM, and
# QUANTIZATION
INFERENCE ?= single
DATA_SAMPLE_NUM ?= 0
QUANTIZATION ?= 0

# Create the build directories if they don't exist
build_dirs:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_BIN_DIR)
	mkdir -p $(BUILD_OBJ_DIR)
	mkdir -p $(BUILD_SRC_DIR)
	mkdir -p $(BUILD_HEX_DIR)
	mkdir -p $(TRACE_DIR)

# Compile all benchmarks
all: SDG_02 SDG_03_Cardiotocography SDG_03_Arrhythmia_Detection SDG_06 SDG_07 SDG_09 SDG_10 SDG_11 SDG_12 SDG_13 # SDG_15 Excluding SDG_15 due to high runtime

# Compile each benchmark with inference type and sample number
SDG_02:
	$(MAKE) compile_inference SDG_DIR=SDG_02_Zero_Hunger C_FILE=food_spoilage_detection BIN_FILE=SDG_02_food_spoilage_detection

SDG_03_Cardiotocography:
	$(MAKE) compile_inference SDG_DIR=SDG_03_Good_Health_and_Well_Being_Cardiotocography C_FILE=cardiotocography BIN_FILE=SDG_03_cardiotocography

SDG_03_Arrhythmia_Detection:
	$(MAKE) compile_inference SDG_DIR=SDG_03_Good_Health_and_Well_Being_Arrhythmia_Detection C_FILE=appt BIN_FILE=SDG_03_arrhythmia_detection

SDG_06:
	$(MAKE) compile_inference SDG_DIR=SDG_06_Clean_Water_and_Sanitation C_FILE=water_quality_monitoring BIN_FILE=SDG_06_water_quality_monitoring

SDG_07:
	$(MAKE) compile_inference SDG_DIR=SDG_07_Affordable_and_Clean_Energy C_FILE=hvac BIN_FILE=SDG_07_hvac

SDG_09:
	$(MAKE) compile_inference SDG_DIR=SDG_09_Industry_Innovation_and_Infrastructure C_FILE=package_tracking BIN_FILE=SDG_09_package_tracking

SDG_10:
	$(MAKE) compile_inference SDG_DIR=SDG_10_Reduced_Inequality C_FILE=gesture_recognition BIN_FILE=SDG_10_gesture_recognition

SDG_11:
	$(MAKE) compile_inference SDG_DIR=SDG_11_Sustainable_Communities_and_Cities C_FILE=air_pollution_monitoring BIN_FILE=SDG_11_air_pollution_monitoring

SDG_12:
	$(MAKE) compile_inference SDG_DIR=SDG_12_Responsible_Consumption_and_Production C_FILE=odor_detection BIN_FILE=SDG_12_odor_detection

SDG_13:
	$(MAKE) compile_inference SDG_DIR=SDG_13_Climate_Action C_FILE=irrigation BIN_FILE=SDG_13_irrigation

SDG_15:
	$(MAKE) compile_inference SDG_DIR=SDG_15_Life_on_Land C_FILE=tree_tracking BIN_FILE=SDG_15_tree_tracking

# Rule to handle multi-inference and single-inference compilation
compile_inference: build_dirs
	cp $(SRC_DIR)/$(SDG_DIR)/$(INFERENCE)_inference/$(C_FILE).c $(BUILD_SRC_DIR)/
	@if find "$(SRC_DIR)/$(SDG_DIR)/$(INFERENCE)_inference/" -type f -name "*.h" | grep -q .; then \
		cp $(SRC_DIR)/$(SDG_DIR)/$(INFERENCE)_inference/*.h $(BUILD_SRC_DIR)/ ; \
		echo "cp $(SRC_DIR)/$(SDG_DIR)/$(INFERENCE)_inference/*.h $(BUILD_SRC_DIR)/"; \
	fi 
	cp $(SRC_DIR)/asm/init.s $(BUILD_SRC_DIR)/
	@if [ "$(INFERENCE)" = "multi" ]; then \
		if [ -e "$(SRC_DIR)/$(SDG_DIR)/samples.csv" ]; then \
			$(PYTHON) $(SRC_DIR)/$(SDG_DIR)/multi_inference/gen-multi-sample.py $(SRC_DIR)/$(SDG_DIR)/samples.csv $(BUILD_SRC_DIR)/ $(QUANTIZATION); \
		fi ; \
		$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/init.s -o $(BUILD_OBJ_DIR)/init.o; \
		$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/$(C_FILE).c -o $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o; \
		$(CC) $(CCFLAGS) -o $(BUILD_BIN_DIR)/$(BIN_FILE)_multi_inference $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o $(BUILD_OBJ_DIR)/init.o; \
	elif [ "$(INFERENCE)" = "single" ]; then \
		if [ -e "$(SRC_DIR)/$(SDG_DIR)/samples.csv" ]; then \
			$(PYTHON) $(SRC_DIR)/$(SDG_DIR)/single_inference/gen-sample.py $(SRC_DIR)/$(SDG_DIR)/samples.csv $(BUILD_SRC_DIR)/ $(DATA_SAMPLE_NUM) $(QUANTIZATION); \
		fi ; \
		$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/init.s -o $(BUILD_OBJ_DIR)/init.o; \
		$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/$(C_FILE).c -o $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o; \
		$(CC) $(CCFLAGS) -o $(BUILD_BIN_DIR)/$(BIN_FILE)_single_inference_sample_$(DATA_SAMPLE_NUM) $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o $(BUILD_OBJ_DIR)/init.o; \
	fi

# Compile each benchmark into a hexfile
SDG_02_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_02_Zero_Hunger C_FILE=food_spoilage_detection BIN_FILE=SDG_02_food_spoilage_detection

SDG_03_Cardiotocography_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_03_Good_Health_and_Well_Being_Cardiotocography C_FILE=cardiotocography BIN_FILE=SDG_03_cardiotocography

SDG_03_Arrhythmia_Detection_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_03_Good_Health_and_Well_Being_Arrhythmia_Detection C_FILE=appt BIN_FILE=SDG_03_arrhythmia_detection

SDG_06_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_06_Clean_Water_and_Sanitation C_FILE=water_quality_monitoring BIN_FILE=SDG_06_water_quality_monitoring

SDG_07_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_07_Affordable_and_Clean_Energy C_FILE=hvac BIN_FILE=SDG_07_hvac

SDG_09_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_09_Industry_Innovation_and_Infrastructure C_FILE=package_tracking BIN_FILE=SDG_09_package_tracking

SDG_10_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_10_Reduced_Inequality C_FILE=gesture_recognition BIN_FILE=SDG_10_gesture_recognition

SDG_11_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_11_Sustainable_Communities_and_Cities C_FILE=air_pollution_monitoring BIN_FILE=SDG_11_air_pollution_monitoring

SDG_12_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_12_Responsible_Consumption_and_Production C_FILE=odor_detection BIN_FILE=SDG_12_odor_detection

SDG_13_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_13_Climate_Action C_FILE=irrigation BIN_FILE=SDG_13_irrigation

SDG_15_serv:
	$(MAKE) compile_hex SDG_DIR=SDG_15_Life_on_Land C_FILE=tree_tracking BIN_FILE=SDG_15_tree_tracking

compile_hex: build_dirs
	cp $(SRC_DIR)/$(SDG_DIR)/single_inference/$(C_FILE).c $(BUILD_SRC_DIR)/
	@if find "$(SRC_DIR)/$(SDG_DIR)/single_inference/" -type f -name "*.h" | grep -q .; then \
		cp $(SRC_DIR)/$(SDG_DIR)/single_inference/*.h $(BUILD_SRC_DIR)/ ; \
		echo "cp $(SRC_DIR)/$(SDG_DIR)/single_inference/*.h $(BUILD_SRC_DIR)/"; \
	fi 
	cp $(SRC_DIR)/asm/init-serv.s $(BUILD_SRC_DIR)/
	if [ -e "$(SRC_DIR)/$(SDG_DIR)/samples.csv" ]; then \
		$(PYTHON) $(SRC_DIR)/$(SDG_DIR)/single_inference/gen-sample.py $(SRC_DIR)/$(SDG_DIR)/samples.csv $(BUILD_SRC_DIR)/ $(DATA_SAMPLE_NUM) $(QUANTIZATION); \
	fi ; \
	$(CC) $(CCFLAGS_SERV) -c $(BUILD_SRC_DIR)/init-serv.s -o $(BUILD_OBJ_DIR)/init-serv.o;
	$(CC) $(CCFLAGS_SERV) -c $(BUILD_SRC_DIR)/$(C_FILE).c -o $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o; 
	$(CC) $(CCFLAGS_SERV) -o $(BUILD_OBJ_DIR)/$(BIN_FILE)_serv_sample_$(DATA_SAMPLE_NUM).elf $(BUILD_OBJ_DIR)/init-serv.o $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o 
	$(RV_PREFIX)objcopy -O binary $(BUILD_OBJ_DIR)/$(BIN_FILE)_serv_sample_$(DATA_SAMPLE_NUM).elf $(BUILD_OBJ_DIR)/$(BIN_FILE)_serv_sample_$(DATA_SAMPLE_NUM).bin
	$(PYTHON) cycle-level/makehex.py $(BUILD_OBJ_DIR)/$(BIN_FILE)_serv_sample_$(DATA_SAMPLE_NUM).bin > $(BUILD_HEX_DIR)/$(BIN_FILE)_serv_sample_$(DATA_SAMPLE_NUM).hex

trace: build_dirs
	@for file in $(BUILT_FILES); do \
	       	instruction-level/gen-trace.sh $$file $(TRACE_DIR) &\
	       	done

kernel_ablation: build_dirs
	$(MAKE) compile_inference_kernel C_FILE=knn_large
	$(MAKE) compile_inference_kernel C_FILE=knn_medium
	$(MAKE) compile_inference_kernel C_FILE=knn_small
	$(MAKE) compile_inference_kernel C_FILE=decision_tree_large
	$(MAKE) compile_inference_kernel C_FILE=decision_tree_medium
	$(MAKE) compile_inference_kernel C_FILE=decision_tree_small
	$(MAKE) compile_inference_kernel C_FILE=logistic_regression
	$(MAKE) compile_inference_kernel C_FILE=mlp

compile_inference_kernel: build_dirs
	cp $(ABLATION_SRC)/food-spoilage-generic.c $(BUILD_SRC_DIR)/
	@if find "$(ABLATION_SRC)/" -type f -name "*.h" | grep -q .; then \
		cp $(ABLATION_SRC)/*.h $(BUILD_SRC_DIR)/ ; \
	fi 
	cp $(ABLATION_SRC)/$(C_FILE).c $(BUILD_SRC_DIR)/
	cp $(SRC_DIR)/asm/init.s $(BUILD_SRC_DIR)/
	$(PYTHON) $(ABLATION_SRC)/gen-sample.py $(ABLATION_SRC)/samples.csv $(BUILD_SRC_DIR)/ $(DATA_SAMPLE_NUM) $(QUANTIZATION); \
	$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/init.s -o $(BUILD_OBJ_DIR)/init.o; \
	$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/food-spoilage-generic.c -o $(BUILD_OBJ_DIR)/food-spoilage-generic.o; \
	$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/$(C_FILE).c -o $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o; \
	$(CC) $(CCFLAGS) -o $(BUILD_BIN_DIR)/food_kernel_$(C_FILE)_sample_$(DATA_SAMPLE_NUM) $(BUILD_OBJ_DIR)/food-spoilage-generic.o $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o $(BUILD_OBJ_DIR)/init.o; \

kernel_ablation_serv:
	$(MAKE) compile_ablation_hex C_FILE=knn_large
	$(MAKE) compile_ablation_hex C_FILE=knn_medium
	$(MAKE) compile_ablation_hex C_FILE=knn_small
	$(MAKE) compile_ablation_hex C_FILE=decision_tree_large
	$(MAKE) compile_ablation_hex C_FILE=decision_tree_medium
	$(MAKE) compile_ablation_hex C_FILE=decision_tree_small
	$(MAKE) compile_ablation_hex C_FILE=logistic_regression
	$(MAKE) compile_ablation_hex C_FILE=mlp

compile_ablation_hex: build_dirs
	cp $(ABLATION_SRC)/food-spoilage-generic.c $(BUILD_SRC_DIR)/
	@if find "$(ABLATION_SRC)/" -type f -name "*.h" | grep -q .; then \
		cp $(ABLATION_SRC)/*.h $(BUILD_SRC_DIR)/ ; \
	fi 
	cp $(ABLATION_SRC)/$(C_FILE).c $(BUILD_SRC_DIR)/
	cp $(SRC_DIR)/asm/init.s $(BUILD_SRC_DIR)/
	$(PYTHON) $(ABLATION_SRC)/gen-sample.py $(ABLATION_SRC)/samples.csv $(BUILD_SRC_DIR)/ $(DATA_SAMPLE_NUM) $(QUANTIZATION);
	$(CC) $(CCFLAGS_SERV) -c $(BUILD_SRC_DIR)/init-serv.s -o $(BUILD_OBJ_DIR)/init-serv.o;
	$(CC) $(CCFLAGS_SERV) -c $(BUILD_SRC_DIR)/food-spoilage-generic.c -o $(BUILD_OBJ_DIR)/food-spoilage-generic.o;
	$(CC) $(CCFLAGS_SERV) -c $(BUILD_SRC_DIR)/$(C_FILE).c -o $(BUILD_OBJ_DIR)/$(C_FILE).o;
	$(CC) $(CCFLAGS_SERV) -o $(BUILD_OBJ_DIR)/food_kernel_$(C_FILE)_serv_sample_$(DATA_SAMPLE_NUM).elf $(BUILD_OBJ_DIR)/init-serv.o $(BUILD_OBJ_DIR)/food-spoilage-generic.o $(BUILD_OBJ_DIR)/$(C_FILE).o 
	$(RV_PREFIX)objcopy -O binary $(BUILD_OBJ_DIR)/food_kernel_$(C_FILE)_serv_sample_$(DATA_SAMPLE_NUM).elf $(BUILD_OBJ_DIR)/food_kernel_$(C_FILE)_serv_sample_$(DATA_SAMPLE_NUM).bin
	$(PYTHON) cycle-level/makehex.py $(BUILD_OBJ_DIR)/food_kernel_$(C_FILE)_serv_sample_$(DATA_SAMPLE_NUM).bin > $(BUILD_HEX_DIR)/food_kernel_$(C_FILE)_serv_sample_$(DATA_SAMPLE_NUM).hex

clean:
	rm -rf $(BUILD_DIR)
