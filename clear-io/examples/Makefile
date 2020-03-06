# To run: 'make example'

CC=gcc
C_FLAGS=-Wall -W -Wextra -I $(SRC_DIR)
SRC_DIR=../src

clear-io.o: $(SRC_DIR)/clear-io.c $(SRC_DIR)/clear-io.h
	$(CC) -c $(C_FLAGS) $(SRC_DIR)/clear-io.c  -o clear-io.o

example_get_string: example_get_string1.c example_get_string2.c clear-io.o
	$(CC) $(C_FLAGS) example_get_string1.c clear-io.o -o example_get_string1
	$(CC) $(C_FLAGS) example_get_string2.c clear-io.o -o example_get_string2

example:
	@make --no-print-directory example_get_string

clean:
	rm clear-io.o example_get_string?

