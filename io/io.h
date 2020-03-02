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
 * Terminating null byte ('\0') is stored after the last character in the buffer.
 *
 * FAIL:    returns EOF if end of file is reached.
 * SUCCESS: returns length of read string.
 */
int get_string(char* dest, size_t size);

/*
 * Reads in a sequence of non-white space characters of
 * max size 255 from stdin and tries to convert it to a SIGNED INTEGER.
 *
 * FAIL:    returns EOF if end of file is reached.
 *          returns 0 if input is empty line, non-numeric or out of integer range.
 * SUCCESS: returns 1.
 */
int get_int(int* dest);

/*
 * Reads in a sequence of non-white space characters of
 * max size 255 from stdin and tries to convert it to a FLOAT.

 * FAIL:    returns EOF if end of file is reached.
 *          returns 0 if input is empty line, non-numeric or out of float range.
 * SUCCESS: returns 1.
 */
int get_float(float* dest);

#endif  // DEFY_THE_FLOW_IO_H
