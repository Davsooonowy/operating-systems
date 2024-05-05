CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
TIME = /usr/bin/time

.PHONY: all clean time_count

all: main tests

main: integration.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

tests: main
	$(TIME) ./$(BUILD_DIR)/main 10 10
	$(TIME) ./$(BUILD_DIR)/main 100 10
	$(TIME) ./$(BUILD_DIR)/main 100 100
	$(TIME) ./$(BUILD_DIR)/main 1000 1000

time_count: main
	$(TIME) ./$(BUILD_DIR)/main 10 10
	$(TIME) ./$(BUILD_DIR)/main 100 10
	$(TIME) ./$(BUILD_DIR)/main 100 100
	$(TIME) ./$(BUILD_DIR)/main 1000 1000

clean:
	rm -rf $(BUILD_DIR)
