CC=gcc
BUILD_DIR=build
BUILD := debug
cflags.common := -std=c11 -Wall
cflags.debug := -g -O0
cflags.release := -O2
CFLAGS := ${cflags.${BUILD}} ${cflags.common}

.PHONY: all clean

all: make_processes tests

make_processes: make_processes.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $< -D BYTES

tests: make_processes
	./$(BUILD_DIR)/make_processes 20


clean:
	rm -rf $(BUILD_DIR)