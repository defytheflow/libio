CC = gcc
CFLAGS  = -fPIC -W -Wall -Wextra
LDFLAGS = -shared

INC   = include/clear-io.h
SRCS  = src/clear-io.c
OBJS  = clear-io.o

TARGET_LIB = libclear-io.so

LIB_DEST_DIR = /usr/local/lib
INC_DEST_DIR = /usr/local/include

.PHONY: all
all: install

$(OBJS): $(SRCS) $(INC)
	$(CC) -c $(CFLAGS) $(SRCS)

$(TARGET_LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

.PHONY: install
install: $(TARGET_LIB) $(INC)
	sudo mv $(TARGET_LIB) $(LIB_DEST_DIR)
	sudo cp $(INC) $(INC_DEST_DIR)
	@make --no-print-directory clean

.PHONY: clean
clean:
	rm -f $(TARGET_LIB) $(OBJS)

