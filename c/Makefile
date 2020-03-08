CC = gcc
CFLAGS   = -fPIC -W -Wall -Wextra
INCFLAGS = -I $(INC_DIR)
LDFLAGS  = -shared

SRC_DIR  = src
INC_DIR  = include
TEST_DIR = tests

INCS  = $(INC_DIR)/clear-io.h $(INC_DIR)/clear-io-in.h \
        $(INC_DIR)/clear-io-out.h $(INC_DIR)/clear-io-err.h

SRCS  = $(SRC_DIR)/clear-io-in.c $(SRC_DIR)/clear-io-out.c \
        $(SRC_DIR)/clear-io-err.c

OBJS  = clear-io-in.o clear-io-out.o clear-io-err.o

TARGET_LIB = libclear-io.so

LIB_DEST_DIR  = /usr/local/lib
INC_DEST_DIR = /usr/local/include

TEST_SRCS = $(TEST_DIR)/test_clear_io.c
TARGET_TEST = test_clear_io

.PHONY: all install test clean

all: install

$(OBJS): $(SRCS) $(INCS)
	$(CC) -c $(CFLAGS) $(INCFLAGS) $(SRCS)

$(TARGET_LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(TARGET_TEST): $(TEST_SRCS) $(OBJS)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@

install: $(TARGET_LIB) $(INCS)
	sudo mv $(TARGET_LIB) $(LIB_DEST_DIR)
	sudo cp $(INCS) $(INC_DEST_DIR)
	@make --no-print-directory clean

test: $(TARGET_TEST)
	shunit2 $(TEST_DIR)/test_clear_io.sh

clean:
	rm -f $(TARGET_LIB) $(TARGET_TEST) $(OBJS)
