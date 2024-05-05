CC=gcc
cflags := -Wall
BUILD_DIR = build

.PHONY: all clean

all: signal_handling test


signal_handling: signal_handling.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(cflags) -o $(BUILD_DIR)/$@ $<

test: signal_handling
	./$(BUILD_DIR)/signal_handling none
	./$(BUILD_DIR)/signal_handling ignore
	./$(BUILD_DIR)/signal_handling handler
	./$(BUILD_DIR)/signal_handling mask

clean:
	rm -rf $(BUILD_DIR)