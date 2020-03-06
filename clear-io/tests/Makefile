# To run tests: 'make test'

SRC=../src

CFLAGS=-Wall -W -Wextra -I $(SRC)

clear-io.o: $(SRC)/clear-io.c $(SRC)/clear-io.h
	gcc -c $(CFLAGS) $(SRC)/clear-io.c  -o clear-io.o

test_get_string: test_get_string.c clear-io.o
	gcc $(CFLAGS) test_get_string.c clear-io.o -o test_get_string

test_get_int: test_get_int.c clear-io.o
	gcc $(CFLAGS) test_get_int.c clear-io.o -o test_get_int

test_get_float: test_get_float.c clear-io.o
	gcc $(CFLAGS) test_get_float.c clear-io.o -o test_get_float

test_clear_io: test_get_string test_get_int test_get_float test_clear_io.sh
	shunit2 test_clear_io.sh

test:
	@make --no-print-directory test_clear_io

clean:
	rm *.o test_get_string test_get_int test_get_float
