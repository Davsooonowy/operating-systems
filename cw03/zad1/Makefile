CC=gcc
BUILD_DIR=build
BUILD := debug

cflags.common := -std=c11 -Wall
cflags.debug := -g -O0
cflags.release := -O2
CFLAGS := ${cflags.${BUILD}} ${cflags.common}
TIME := /usr/bin/time
RAPORT := pomiar_zad_2.txt

.PHONY: all tests clean

all: reverse reverse_bytes tests

reverse_bytes: reverse.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $< -D BYTE_MODE

reverse: reverse.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

test_generator: test_generator.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

tests:
	make ftests REVERSE=reverse BUILD=release
	make ftests REVERSE=reverse_bytes BUILD=release

	rm -f pomiar_zad_2.txt
	touch pomiar_zad_2.txt

	make time_measure REVERSE=reverse BUILD=release
	echo >> pomiar_zad_2.txt
	make time_measure REVERSE=reverse_bytes BUILD=release
	echo >> pomiar_zad_2.txt


gen_tests: test_generator
	mkdir -p test_files
	./$(BUILD_DIR)/test_generator 15420 			test_files/file1
	./$(BUILD_DIR)/test_generator 53269 			test_files/file2
	./$(BUILD_DIR)/test_generator 420420 			test_files/file3
	./$(BUILD_DIR)/test_generator 1696969 		test_files/file4

ftests: $(REVERSE) gen_tests
	mkdir -p test_temp

	./$(BUILD_DIR)/$(REVERSE) test_files/file1 test_temp/file1_rev
	./$(BUILD_DIR)/$(REVERSE) test_temp/file1_rev test_temp/file1_rev_rev
	./$(BUILD_DIR)/$(REVERSE) test_files/file2 test_temp/file2_rev
	./$(BUILD_DIR)/$(REVERSE) test_temp/file2_rev test_temp/file2_rev_rev
	./$(BUILD_DIR)/$(REVERSE) test_files/file3 test_temp/file3_rev
	./$(BUILD_DIR)/$(REVERSE) test_temp/file3_rev test_temp/file3_rev_rev
	./$(BUILD_DIR)/$(REVERSE) test_files/file4 test_temp/file4_rev
	./$(BUILD_DIR)/$(REVERSE) test_temp/file4_rev test_temp/file4_rev_rev

	diff -s test_files/file1 test_temp/file1_rev_rev
	rev test_files/file1 | diff -s test_temp/file1_rev -  # | przekazuje wynik z lewej strony do prawej

	diff -s test_files/file2 test_temp/file2_rev_rev
	rev test_files/file2 | diff -s test_temp/file2_rev -

	diff -s test_files/file3 test_temp/file3_rev_rev
	rev test_files/file3 | diff -s test_temp/file3_rev -

	diff -s test_files/file4 test_temp/file4_rev_rev
	rev test_files/file4 | diff -s test_temp/file4_rev -


time_measure: $(REVERSE) gen_tests
	echo "Time measure for $(REVERSE)" >> $(RAPORT)
	echo "File 1: " 		`$(TIME) -f '%e' ./$(BUILD_DIR)/$(REVERSE) test_files/file1 		test_temp/file1_rev 		2>&1` "s" >> $(RAPORT)
	echo "File 2: " 	`$(TIME) -f '%e' ./$(BUILD_DIR)/$(REVERSE) test_files/file2 		test_temp/file2_rev 		2>&1` "s" >> $(RAPORT)
	echo "File 3: " 		`$(TIME) -f '%e' ./$(BUILD_DIR)/$(REVERSE) test_files/file3 		test_temp/file3_rev 		2>&1` "s" >> $(RAPORT)
	echo "File 4: " 		`$(TIME) -f '%e' ./$(BUILD_DIR)/$(REVERSE) test_files/file4 		test_temp/file4_rev 		2>&1` "s" >> $(RAPORT)


clean:
	rm -rf $(BUILD_DIR) test_files test_temp
	rm -f $(RAPORT)