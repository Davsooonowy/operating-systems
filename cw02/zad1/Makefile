CC=gcc

BUILD_DIR=build

BUILD := debug

cflags.common := -std=c11 -Wall

cflags.debug := -g -O0

cflags.release := -O2

CFLAGS := ${cflags.${BUILD}} ${cflags.common}

.PHONY: all main_static main_shared main_dynamic clean



all:
	make main_static
	make main_shared
	make main_dynamic

main_static: mainStatic.c
	mkdir -p $(BUILD_DIR)
	make -C collatzLib collatz_static BUILD=$(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $< collatzLib/build/libcollatz_static.a

main_shared: mainShared.c
	mkdir -p $(BUILD_DIR)
	make collatz_shared -C collatzLib BUILD=$(BUILD)
	$(CC) $(CFLAGS) -L ./collatzLib/build $< -lcollatz_shared -Wl,-rpath=./collatzLib/build -o $(BUILD_DIR)/$@

main_dynamic: mainDynamic.c
	mkdir -p $(BUILD_DIR)
	make collatz_shared -C collatzLib BUILD=$(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $< -ldl



run_static: main_static
	./$(BUILD_DIR)/main_static

run_shared: main_shared
	./$(BUILD_DIR)/main_shared

run_dynamic: main_dynamic
	./$(BUILD_DIR)/main_dynamic

debug_static: main_static
	gdb ./$(BUILD_DIR)/main_static

debug_shared: main_shared
	gdb ./$(BUILD_DIR)/main_shared

debug_dynamic: main_dynamic
	gdb ./$(BUILD_DIR)/main_dynamic



clean:
	rm -rf $(BUILD_DIR)
	make -C ./collatzLib clean