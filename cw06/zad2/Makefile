CC=gcc
CFLAGS := -Wall
BUILD_DIR = build

.PHONY: all clean

all: first other

first: first.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

other: other.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

# use -j flag to parallelize the execution of the two programs
run: all
	./$(BUILD_DIR)/first 0 1 100 & ./$(BUILD_DIR)/other

clean:
	rm -rf $(BUILD_DIR)
	rm input_pipe output_pipe