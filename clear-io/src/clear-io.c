#include "clear-io.h"

#include <errno.h>   // ERANGE
#include <float.h>   // FLT_MAX
#include <ctype.h>   // isspace()
#include <stdio.h>   // getchar(), printf()
#include <stddef.h>  // size_t, NULL
#include <stdlib.h>  // strtol(), strtod()
#include <limits.h>  // INT_MAX, INT_MIN

#define TEMP_BUFFER_SIZE 256

size_t get_line(const char* prompt, char* dest, size_t size)
/*
 * RETURN VALUE:
 *     FAILURE - 0 if end of file was reached.
 *     SUCCESS - number of characters read into 'dest' (including '\n').
 */
{
        int c;
        size_t len;

        len = 0;

        if (prompt != NULL)
                printf("%s", prompt);

        // while not overflowed 'dest', reached end of line or EOF
        while (len < size - 1 && (c = getchar()) != '\n' && c != EOF)
                dest[len++] = c;

        if (c == '\n')
                dest[len++] = c;

        dest[len] = '\0';

        return len;
}

size_t get_string(const char* prompt, char* dest, size_t size)
/*
 * RETURN VALUE:
 *     FAILURE - 0 if end of file was reached.
 *     SUCCESS - number of non-whitespace characters read into 'dest'.
 */
{
        int c;
        size_t len;

        if (prompt != NULL)
                printf("%s", prompt);

        // Try to read a sequence of non-whitespace characters into 'dest'
        // while not overflowed 'dest' or reached EOF
        for (len = 0; len < size - 1 && (c = getchar()) != EOF;) {

                if (isspace(c) && len == 0)
                        continue;

                if (isspace(c) && len != 0) {
                        dest[len] = '\0';
                        break;
                }

                dest[len++] = c;
        }

        return len;
}

int get_int(const char* prompt, int* dest)
/*
 * RETURN VALUE:
 *     FAILURE - EOF if end of file was reached,
 *               0   if input is non-numeric or not in SIGNED INTEGER range.
 *     SUCCESS - 1.
 */
{
        long l;
        char* endptr;  // address of first invalid character read by 'strtol'.
        char temp_buffer[TEMP_BUFFER_SIZE];

        if (get_string(prompt, temp_buffer, TEMP_BUFFER_SIZE) == 0)
                return EOF;

        l = strtol(temp_buffer, &endptr, 10);

        if (endptr == temp_buffer)
                // no valid characters were read by 'strtol'.
                return 0;

        if (*endptr && *endptr != '\n')
                // only part of input was converted by 'strtol'.
                return 0;

        if (errno == ERANGE)
                // input doesn't fit into a double.
                return 0;

        if (l < INT_MIN || l > INT_MAX)
                // input doesnt't fit into float.
                return 0;

        *dest = (int) l;

        return 1;
}

int get_float(const char* prompt, float* dest)
/*
 * RETURN VALUE:
 *     FAILURE - EOF if end of file was reached,
 *               0   if input is non-numeric or not in FLOAT range.
 *     SUCCESS - 1.
 */
{
        double d;
        char* endptr;  // address of first invalid character read by 'strtod'.
        char temp_buffer[TEMP_BUFFER_SIZE];

        if (get_string(prompt, temp_buffer, TEMP_BUFFER_SIZE) == 0)
                return EOF;

        d = strtod(temp_buffer, &endptr);

        if (endptr == temp_buffer)
                // no valid characters were read by 'strtod'.
                return 0;

        if (*endptr && *endptr != '\n')
                // only part of input was converted by 'strtod'.
                return 0;

        if (errno == ERANGE)
                // input doesn't fit into a double.
                return 0;

        if (d < -FLT_MAX || d > FLT_MAX)
                // input doesnt't fit into float.
                return 0;

        *dest = (float) d;

        return 1;
}
