#include "more-string.h"

#include <string.h>

void strrev(char* dest, const char* src)
{
        int i, j, len;

        len = strlen(src);
        for (i = len - 1, j = 0; (dest[j] = src[i]) != '\0'; --i, ++j);
}
