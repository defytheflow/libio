SRC=../src
C_FLAGS=-Wall -W -Wextra -I $(SRC)

safeio.o: $(SRC)/safeio.c $(SRC)/safeio.h
	gcc -c $(C_FLAGS) $(SRC)/safeio.c

test_get_int: test_get_int.c safeio.o
	gcc $(C_FLAGS) test_get_int.c safeio.o -o test_get_int

clean:
	rm safeio.o test_get_int
