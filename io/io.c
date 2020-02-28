#include "io.h"

#include <ctype.h>
#include <stdio.h>
#include <assert.h>

size_t get_line(char* buffer, size_t size)
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

size_t get_word(char* buffer, size_t size)
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

size_t get_string(char* buffer, size_t size)
{
        assert(buffer != NULL && "'get_line' - null pointer error.");

        int c, i;

        i = 0;
        while ((c = getchar()) != EOF && c != '\n' && i < size - 1)
                buffer[i++] = c;

        buffer[i] = '\0';
        return i;
}

