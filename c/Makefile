CC = gcc
CFLAGS = -fPIC -W -Wall -Wextra
LDFLAGS = -shared

SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests

INCLUDES = $(INCLUDE_DIR)/*.h
SRCS = $(SRC_DIR)/*.c
OBJS = io-in.o io-err.o

# Test
TEST_SRCS = $(TEST_DIR)/*.c
TARGET_TEST = test_io

TARGET_LIB = libio.so

LIB_DEST_DIR  = /usr/local/lib
INC_DEST_DIR = /usr/local/include

.PHONY: all install test clean

all: install

$(OBJS): $(SRCS) $(INCLUDES)
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) $(SRCS)

$(TARGET_LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

install: $(TARGET_LIB) $(INCLUDES)
	sudo mv $(TARGET_LIB) $(LIB_DEST_DIR)
	sudo cp $(INCLUDES) $(INC_DEST_DIR)
	@make --no-print-directory clean

$(TARGET_TEST): $(TEST_SRCS) $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $@

test: $(TARGET_TEST)
	shunit2 $(TEST_DIR)/test_io.sh

clean:
	$(RM) -f $(TARGET_LIB) $(TARGET_TEST) $(OBJS)
