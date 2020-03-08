# To run tests: 'make test'

CC=gcc
CFLAGS=-Wall -W -Wextra -I $(SRC_DIR)
SRC_DIR=../src
TST_DIR=../tests

clear-io.o: $(SRC_DIR)/clear-io.c $(SRC_DIR)/clear-io.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/clear-io.c  -o clear-io.o

test_get_string: test_get_string.c clear-io.o
	$(CC) $(CFLAGS) test_get_string.c clear-io.o -o test_get_string

test_get_int: test_get_int.c clear-io.o
	$(CC) $(CFLAGS) test_get_int.c clear-io.o -o test_get_int

test_get_float: test_get_float.c clear-io.o
	$(CC) $(CFLAGS) test_get_float.c clear-io.o -o test_get_float

test_clear_io: test_get_string test_get_int test_get_float test_clear_io.sh
	shunit2 test_clear_io.sh

test:
	@make --no-print-directory test_clear_io

.PHONY: clean
clean:
	rm *.o test_get_string test_get_int test_get_float
