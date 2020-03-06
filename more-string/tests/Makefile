# To run tests: 'make test'
CC=gcc
CFLAGS=-Wall -W -Wextra -I $(SRC)
LIBS=-lcheck -lm -lpthread -lrt -lsubunit
SRC=../src

more-string.o: $(SRC)/more-string.c $(SRC)/more-string.h
	$(CC) -c $(CFLAGS) $(SRC)/more-string.c  -o more-string.o

test_more_string.o: test_more_string.c
	$(CC) -c $(CFLAGS) test_more_string.c

test_more_string: test_more_string.o more-string.o
	$(CC) $(CFLAGS) test_more_string.o more-string.o $(LIBS) -o test_more_string

test:
	@make --no-print-directory test_more_string

clean:
	rm *.o test_more_string
