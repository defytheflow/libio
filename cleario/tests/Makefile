# To run tests: 'make test'

SRC=../src
C_FLAGS=-Wall -W -Wextra -I $(SRC)

cleario.o: $(SRC)/cleario.c $(SRC)/cleario.h
	gcc -c $(C_FLAGS) $(SRC)/cleario.c  -o cleario.o

test_get_string: test_get_string.c cleario.o
	gcc $(C_FLAGS) test_get_string.c cleario.o -o test_get_string

test_get_int: test_get_int.c cleario.o
	gcc $(C_FLAGS) test_get_int.c cleario.o -o test_get_int

test_get_float: test_get_float.c cleario.o
	gcc $(C_FLAGS) test_get_float.c cleario.o -o test_get_float

test_cleario: test_get_string test_get_int test_get_float test_cleario.sh
	shunit2 test_cleario.sh

test:
	@make --no-print-directory test_cleario

clean_cleario:
	clean -f

clean:
	@make -s clean_cleario

