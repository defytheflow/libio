CC = gcc
CFLAGS  = -fPIC -W -Wall -Wextra
LDFLAGS = -shared

SRC_DIR  = src
INC_DIR  = include
TEST_DIR = tests

INC   = $(INC_DIR)/clear-io.h
SRCS  = $(SRC_DIR)/clear-io.c
OBJS  = clear-io.o

TARGET_LIB = libclear-io.so

LIB_DEST_DIR  = /usr/local/lib
INC_DEST_DIR = /usr/local/include

TEST_SRCS = $(TEST_DIR)/test_clear_io.c
TARGET_TEST = test_clear_io

.PHONY: all install test clean

all: install

$(OBJS): $(SRCS) $(INC)
	$(CC) -c $(CFLAGS) $(SRCS)

$(TARGET_LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(TARGET_TEST): $(TEST_SRCS) $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $^ -o $@

install: $(TARGET_LIB) $(INC)
	sudo mv $(TARGET_LIB) $(LIB_DEST_DIR)
	sudo cp $(INC) $(INC_DEST_DIR)
	@make --no-print-directory clean

test: $(TARGET_TEST)
	shunit2 $(TEST_DIR)/test_clear_io.sh

clean:
	rm -f $(TARGET_LIB) $(TARGET_TEST) $(OBJS)
