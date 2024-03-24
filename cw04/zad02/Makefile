CC=gcc
BUILD_DIR=build
BUILD := debug
cflags.common := -std=c11 -Wall
cflags.debug := -g -O0
cflags.release := -O2
CFLAGS := ${cflags.${BUILD}} ${cflags.common}

.PHONY: all clean

all:  zad2 tests

zad2: zad2.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $< -D BYTES

tests: zad2
	mkdir -p test_dir

	./$(BUILD_DIR)/zad2 test_dir
	./$(BUILD_DIR)/zad2 gfddfgdfgdfgfdgsgfd


clean:
	rm -rf $(BUILD_DIR) test_dir