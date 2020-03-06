
SRC=../src
C_FLAGS=-Wall -W -Wextra -I $(SRC)

cleario.o: $(SRC)/cleario.c $(SRC)/cleario.h
	gcc -c $(C_FLAGS) $(SRC)/cleario.c  -o cleario.o

example_get_string: example_get_string.c cleario.o
	gcc $(C_FLAGS) example_get_string.c cleario.o -o example_get_string

clean:
	rm cleario.o example_get_string

