#ifndef CIO_H
#define CIO_H

#include <stddef.h>

/*
 * Reads in at most one less than 'size' characters from stdin
 * and stores them into the 'buffer'.
 *
 * Reading stops after an EOF or a newline. If a newline is
 * read, it is stored into the buffer. A terminating null byte
 * ('\0') is stored after the last character in the 'buffer'.
 *
 * Returns the number of characters read into the 'buffer'
 */
size_t get_line(char* buffer, size_t size);

/*
 * Reads in at most one less than 'size' characters from stdin
 * and stores them into the 'buffer'.
 *
 * Reading stops after an EOF or a newline. Newline is not stored
 * into the 'buffer'. A terminating null byte ('\0') is
 * stored after the last character in the 'buffer'.
 *
 * Returns the number of characters read into the 'buffer'.
 */
size_t get_string(char* buffer, size_t size);

/*
 * Reads in a sequence of non-white space characters (word) of
 * max size ('size' - 1) from stdin and stores it into the 'buffer'.
 *
 * Skips all the leading whitespace characters. Stops reading
 * after meeting the first whispace character after the 'word',
 * EOF or an empty line. Terminating null byte ('\0') is stored after
 * the last character in the buffer.
 *
 * Returns the length of the read word.
 */
size_t get_word(char* buffer, size_t size);

/*
 * Reads in a sequence of non-white space characters (word) of
 * max size 255 from stdin and tries to convert it to a signed integer.
 *
 * Returns 1 on success, 0 on failure.
 *
 * Failure occurs if input is just EOF, empty line, non-numeric or
 * is not in valid INTEGER range.
 */
int get_int(int* dest);

#endif  // CIO_H
