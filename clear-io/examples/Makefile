
SRC=../src
C_FLAGS=-Wall -W -Wextra -I $(SRC)

clear-io.o: $(SRC)/clear-io.c $(SRC)/clear-io.h
	gcc -c $(C_FLAGS) $(SRC)/clear-io.c  -o clear-io.o

example_get_string: example_get_string1.c example_get_string2.c clear-io.o
	gcc $(C_FLAGS) example_get_string1.c clear-io.o -o example_get_string1
	gcc $(C_FLAGS) example_get_string2.c clear-io.o -o example_get_string2

example:
	@make --no-print-directory example_get_string

clean:
	rm clear-io.o example_get_string?

