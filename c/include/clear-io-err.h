#ifndef CLEAR_IO_ERR_H
#define CLEAR_IO_ERR_H

/*
 * Same as fprintf(stderr, format, ...).
 * Prints "Error: " before format.
 */
void simple_error(const char* format, ...);

/*
 * Same as fwprintf(stderr, format, ...).
 * Prints " ☹  Error: " before format.
 */
void smile_error(const char* format, ...);

/*
 * Same as fprintf(stderr, format, ...).
 * Prints "Error: " before format.
 * Calls exit(EXIT_FAILURE).
 */
void fatal_error(const char* format, ...);

#endif  // CLEAR_IO_ERR_H
