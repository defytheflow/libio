#ifndef DEFY_THE_FLOW_IO_H
#define DEFY_THE_FLOW_IO_H

#include <stddef.h>

/*
 * Reads in at most one less than 'size' characters from stdin
 * and stores them into the 'dest'.
 *
 * Reading stops after an EOF or a newline. If a newline is
 * read, it is stored into the buffer. A terminating null byte
 * ('\0') is stored after the last character in the 'dest'.
 *
 * Returns the number of characters read into the 'dest'.
 */
size_t get_line(char* dest, size_t size);


/* Reads in a sequence of non-white space characters of
 * max size ('size' - 1) from stdin and stores it into the 'dest'.
 *
 * Skips all the leading whitespace characters. Stops reading
 * after meeting the first whispace character after the sequence,
 * EOF or an empty line. Terminating null byte ('\0') is stored after
 * the last character in the buffer.
 *
 * Returns the length of the string.
 */
size_t get_string(char* dest, size_t size);

/*
 * Reads in a sequence of non-white space characters of
 * max size 255 from stdin and tries to convert it to a SIGNED INTEGER.
 *
 * Returns 1 on success, 0 on failure.
 *
 * Failure occurs if input is just EOF, empty line, non-numeric or
 * is not in valid INTEGER range.
 */
int get_int(int* dest);

/*
 * Reads in a sequence of non-white space characters of
 * max size 255 from stdin and tries to convert it to a FLOAT.
 *
 * Returns 1 on success, 0 on failure.
 *
 * Failure occurs if input is just EOF, empty line, non-numeric or
 * is not in valid FLOAT range.
 */
int get_float(float* dest);

#endif  // DEFY_THE_FLOW_IO_H
