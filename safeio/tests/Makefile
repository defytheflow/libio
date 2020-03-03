# To run tests: 'make test'

SRC=../src
C_FLAGS=-Wall -W -Wextra -I $(SRC)

safeio.o: $(SRC)/safeio.c $(SRC)/safeio.h
	gcc -c $(C_FLAGS) $(SRC)/safeio.c  -o safeio.o

test_get_int: test_get_int.c safeio.o
	gcc $(C_FLAGS) test_get_int.c safeio.o -o test_get_int

test_get_float: test_get_float.c safeio.o
	gcc $(C_FLAGS) test_get_float.c safeio.o -o test_get_float

test_safeio: test_get_int test_get_float test_safeio.sh
	shunit2 test_safeio.sh

test:
	@make --no-print-directory test_safeio

clean:
	clean -f

