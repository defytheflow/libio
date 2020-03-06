#include "cleario.h"

#include <errno.h>   // ERANGE
#include <float.h>
#include <ctype.h>   // isspace()
#include <stdio.h>
#include <stdlib.h>  // strtol(), strtod()
#include <limits.h>

#define TEMP_BUF_SIZE 256

int get_line(char* dest, size_t size)
/*
 * RETURN VALUE:
 *     FAILURE - 0 if end of file was reached.
 *     SUCCESS - number of characters read into 'dest' (including '\n').
 */
{
        int c, len;

        len = 0;
        // while not reached EOF, end of line, or overflowed 'dest'.
        while ((c = getchar()) != EOF && c != '\n' && len < (signed) size - 1)
                dest[len++] = c;

        if (c == '\n')
                dest[len++] = c;

        dest[len] = '\0';

        return len;
}

int get_string(char* dest, size_t size)
/*
 * RETURN VALUE:
 *     FAILURE - 0 if end of file was reached.
 *     SUCCESS - number of non-whitespace characters read into 'dest'.
 */
{
        int len, c;

        // Try to read a sequence of non-whitespace characters into 'dest'
        // while not reached EOF or overflowed 'dest'.
        for (len = 0; (c = getchar()) != EOF && len < (signed) size - 1;) {

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

int get_int(int* dest)
/*
 * RETURN VALUE:
 *     FAILURE - EOF if end of file was reached,
 *               0   if input is non-numeric or not in SIGNED INTEGER range.
 *     SUCCESS - 1.
 */
{
        long l;
        char* endptr;  // address of first invalid character read by 'strtol'.
        char temp_buffer[TEMP_BUF_SIZE];

        if (get_string(temp_buffer, TEMP_BUF_SIZE) == 0)
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

int get_float(float* dest)
/*
 * RETURN VALUE:
 *     FAILURE - EOF if end of file was reached,
 *               0   if input is non-numeric or not in FLOAT range.
 *     SUCCESS - 1.
 */
{
        double d;
        char* endptr;  // address of first invalid character read by 'strtod'.
        char temp_buffer[TEMP_BUF_SIZE];

        if (get_string(temp_buffer, TEMP_BUF_SIZE) == 0)
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
