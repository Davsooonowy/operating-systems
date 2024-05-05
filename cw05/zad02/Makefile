CC=gcc
CFLAGS=-Wall
BUILD_DIR=build
SOURCES=$(wildcard *.c)
TARGETS=$(SOURCES:%.c=$(BUILD_DIR)/%)

.PHONY: all clean

all: $(TARGETS)

$(BUILD_DIR)/%: %.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)