CC=gcc
BUILD_DIR=build
BUILD := debug

cflags.common := -std=c11 -Wall
cflags.debug := -g -O0
cflags.release := -O2
CFLAGS := ${cflags.${BUILD}} ${cflags.common}

.PHONY: all tests clean

all: calc_size tests

calc_size: calc_size.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<

gen_tests:
	mkdir -p test_dir

	touch test_dir/file1
	touch test_dir/file2
	touch test_dir/file3

	echo "Hello World" > test_dir/file1
	echo "C jest super, a Python dla leszczy" > test_dir/file2
	echo "Systemy Operacyjne super przedmiot, swietnie sie bawue" > test_dir/file3

tests: gen_tests calc_size
		rm -f compare.txt

		echo "calc_size output:" > compare.txt
		./$(BUILD_DIR)/calc_size test_dir >> compare.txt
		echo "" >> compare.txt
		echo "wc --bytes output:" >> compare.txt
		wc --bytes test_dir/* >> compare.txt

clean:
	rm -rf $(BUILD_DIR) test_dir *.txt