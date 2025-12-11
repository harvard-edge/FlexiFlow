CC=gcc

# List of C source files (excluding food-spoilage-generic.c and food-spoilage-multi-generic.c)
SRC_FILES := $(filter-out food-spoilage-generic.c food-spoilage-multi-generic.c, $(wildcard *.c))
GENERIC_SRC := food-spoilage-generic.c
MULTI_GENERIC_SRC := food-spoilage-multi-generic.c

# Remove .c extension for target names
TARGETS := $(basename $(SRC_FILES))

# For each target, also build a multi version
MULTI_TARGETS := $(addsuffix -multi,$(TARGETS))

# Default target: build all
all: $(TARGETS) $(MULTI_TARGETS)

# Pattern rule: each target is built from its .c file and the generic file
%: %.c $(GENERIC_SRC)
	$(CC) $^ -o $@

# Pattern rule: each -multi target is built from its .c file and the multi generic file
%-multi: %.c $(MULTI_GENERIC_SRC)
	$(CC) $^ -o $@

# Clean rule
clean:
	rm -f $(TARGETS) $(MULTI_TARGETS)

.PHONY: all clean
