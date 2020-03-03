#include "safeio.h"

#include <errno.h>   // ERANGE
#include <float.h>
#include <ctype.h>   // isspace()
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>  // strtol(), strtod()
#include <limits.h>

#define BUF_SIZE 256

int get_line(char* dest, size_t size)
/*
 * FAIL:    returns EOF if end of file is reached.
 * SUCCESS: returns number of characters read into 'dest' (including '\n').
 */
{
        assert(dest != NULL && "'get_line' - null pointer error.");

        int c, i;

        i = 0;
        // while not reached EOF, end of line, or overflowed 'dest'
        while ((c = getchar()) != EOF && c != '\n' && i < size - 1)
                dest[i++] = c;

        if (c == '\n')
                dest[i++] = c;

        dest[i] = '\0';

        return feof(stdin) ? EOF : i;
}

int get_string(char* dest, size_t size)
/*
 * FAIL:    returns EOF if end of file is reached.
 * SUCCESS: returns length of read string.
 */
{
        assert(dest != NULL &&  "'get_string' - null pointer error.");

        int i, j;
        char buffer[size];

        if (!fgets(buffer, size, stdin))
                // EOF or input failed
                return feof(stdin) ? EOF : 0;

        // skip whitespace
        for (i = 0; buffer[i] != '\0' && isspace(buffer[i]); ++i);

        // read into dest until end or whitespace
        for (j = 0; buffer[i] != '\0' && !isspace(buffer[i]); ++i, ++j)
                dest[j] = buffer[i];

        dest[j] = '\0';
        return j;
}

int get_int(int* dest)
/*
 * FAIL:    returns EOF if end of file is reached.
 *          returns 0 if input is empty line, non-numeric or out of integer range.
 * SUCCESS: returns 1.
 */
{
        assert(dest != NULL && "'get_int' - null pointer error.");

        int len;  // get_string return value
        long l;
        char* endptr;  // address of first invalid character read by 'strtol'
        char buffer[BUF_SIZE];

        if ((len = get_string(buffer, BUF_SIZE)) == EOF || len == 0)
                // we got an EOF or an empty line
                return (len == EOF) ? EOF : 0;

        l = strtol(buffer, &endptr, 10);

        if (endptr == buffer)
                // we couldn't read a single character.
                return 0;

        if (*endptr && *endptr != '\n')
                // we converted part of the string that looked like an int
                // we didn't convert the whole input
                return 0;

        if (errno == ERANGE)
                // result doesn't fit into a long
                return 0;

        if (l < INT_MIN || l > INT_MAX)
                // result doesnt't fit into int
                return 0;

        *dest = (int) l;
        return 1;
}

int get_float(float* dest)
/*
 * FAIL:    returns EOF if end of file is reached.
 *          returns 0 if input is empty line, non-numeric or out of float range.
 * SUCCESS: returns 1.
 */
{
        assert(dest != NULL && "'get_float' - null pointer error.");

        int len;  // get_string return value
        double d;
        char* endptr; // address of first invalif character read by 'strtol'
        char buffer[BUF_SIZE];

        if ((len = get_string(buffer, BUF_SIZE)) == EOF || len == 0)
                // we got an EOF or an empty line
                return (len == EOF) ? EOF : 0;

        d = strtod(buffer, &endptr);

        if (endptr == buffer)
                // we couldn't read a single character.
                return 0;

        if (*endptr && *endptr != '\n')
                // we converted part of the string that looked like an float
                // we didn't convert the whole input
                return 0;

        if (errno == ERANGE)
                // result doesn't fit into a double
                return 0;

        if (d < -FLT_MAX || d > FLT_MAX)
                // result doesnt't fit into float
                return 0;

        *dest = (float) d;
        return 1;
}
