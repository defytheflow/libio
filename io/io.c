#include "io.h"

#include <errno.h>   // ERANGE
#include <float.h>
#include <ctype.h>   // isspace()
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>  // strtol(), strtod()
#include <limits.h>

#define BUF_SIZE 256

size_t get_line(char* buffer, size_t size)
/* Returns 0 on EOF. */
{
        assert(buffer != NULL && "'get_line' - null pointer error.");

        int c, i;

        i = 0;
        while ((c = getchar()) != EOF && c != '\n' && i < size - 1)
                buffer[i++] = c;

        if (c == '\n')
                buffer[i++] = c;

        buffer[i] = '\0';
        return i;
}

size_t get_string(char* dest, size_t size)
{
        assert(dest != NULL &&  "'get_word' - null pointer error.");

        int i, j;
        char buffer[size];

        if (!fgets(buffer, size, stdin))
                // EOF or input failed
                return 0;

        // skip whitespace
        for (i = 0; buffer[i] != '\0' && isspace(buffer[i]); ++i);

        // read into dest until end or whitespace
        for (j = 0; buffer[i] != '\0' && !isspace(buffer[i]); ++i, ++j)
                dest[j] = buffer[i];

        dest[j] = '\0';
        return j;
}

int get_int(int* dest)
/* Returns 0 on EOF, empty line, non-integer input, out of range. */
{
        assert(dest != NULL && "'get_int' - null pointer error.");

        long l;
        char* endptr;  // address of first invalid character read by 'strtol'
        char buffer[BUF_SIZE];

        if (!get_string(buffer, BUF_SIZE))
                // we got only an EOF or an empty line
                return 0;

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
/* Returns 0 on EOF, empty line, non-float input, out of range. */
{
        assert(dest != NULL && "'get_float' - null pointer error.");

        double d;
        char* endptr; // address of first invalif character read by 'strtol'
        char buffer[BUF_SIZE];

        if (!get_string(buffer, BUF_SIZE))
                // we got only an EOF or an empty line
                return 0;

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
