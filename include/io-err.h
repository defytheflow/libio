#ifndef IO_ERR_H
#define IO_ERR_H

/*
 * Prints "Error: " before format.
 *
 *     if stream orientation is wide:
 *         same as fwprintf(stderr, format, ...)
 *     if stream orientation is byte:
 *         same as fprintf(stderr, format, ...)
 *     if stream orientation is not set:
 *         same as fprintf(stderr, format, ...)
 */
void simple_error(const char* format, ...);

/*
 * Prints " ☹  Error: " or " :( Error: " before format.
 *
 *     if stream orientation is wide:
 *         same as fwprintf(stderr, format, ...)
 *     if stream orientation is byte:
 *         same as fprintf(stderr, format, ...)
 *     if stream orientation is not set:
 *         same as fwprintf(stderr, format, ...)
 *
 * Warning:
 *     If 'stderr' is not set, make is wide-oriented.
 *     Usage of byte-oriented functions will result in an
 *     undefined behavior.
 */
void smile_error(const char* format, ...);

/*
 * Prints "Error: " before format.
 *
 *     if stream orientation is wide:
 *         same as fwprintf(stderr, format, ...)
 *     if stream orientation is byte:
 *         same as fprintf(stderr, format, ...)
 *     if stream orientation is not set:
 *         same as fprintf(stderr, format, ...)
 *
 * Calls exit(EXIT_FAILURE).
 */
void fatal_error(const char* format, ...);

#endif  /* IO_ERR_H */
