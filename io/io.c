#include "io.h"

#include <errno.h>
#include <ctype.h> // isspace()
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>  // strtol()
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

size_t get_string(char* buffer, size_t size)
/* Returns 0 on EOF or on empty line. */
{
        assert(buffer != NULL && "'get_line' - null pointer error.");

        int c, i;

        i = 0;
        while ((c = getchar()) != EOF && c != '\n' && i < size - 1)
                buffer[i++] = c;

        buffer[i] = '\0';
        return i;
}

size_t get_word(char* buffer, size_t size)
/* Returns 0 on EOF or on empty line. */
{
        assert(buffer != NULL &&  "'get_word' - null pointer error.");

        int i, c, seen_word;

        seen_word = i = 0;
        while ((c = getchar()) != EOF && c != '\n' && i < size - 1) {
                if (isspace(c) && seen_word)
                        break;
                else if (isspace(c) && !seen_word)
                        continue;
                else {
                        seen_word = 1;
                        buffer[i++] = c;
                }
        }

        buffer[i] = '\0';
        return i;
}

int get_int(int* dest)
/* Returns 0 on EOF, empty line, non-numeric input, out of range. */
{
        assert(dest != NULL && "'get_int' - null pointer error.");

        long l;
        char* endptr;  // address of first invalid character for strtol
        char buffer[BUF_SIZE];

        if (!get_word(buffer, BUF_SIZE))
                // we got only an EOF or just a new line
                return 0;

        l = strtol(buffer, &endptr, 10);

        if (endptr == buffer)
                // we couldn't read a single character.
                return 0;

        if (*endptr && *endptr != '\n')
                // we converted part of the string that looked like a number
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
