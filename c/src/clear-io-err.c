#include <clear-io-err.h>

#include <locale.h>  // setlocale()
#include <stdarg.h>  // va_list, va_start(), va_end()
#include <stdio.h>   // *printf()
#include <stdlib.h>  // mbstowcs(), exit(), EXIT_FAILURE
#include <string.h>  // strlen()
#include <wchar.h>   // wchar_t

#define SAD_SMILE L'\u2639'

void simple_error(const char* format, ...)
{
        va_list ap;

        if (format) {
                va_start(ap, format);

                fprintf(stderr, "Error: ");
                vfprintf(stderr, format, ap);

                va_end(ap);
        }
}

void smile_error(const char* format, ...)
{
        va_list ap;
        wchar_t w_format[strlen(format) + 1];

        mbstowcs(w_format, format, sizeof(w_format));

        if (format) {
                va_start(ap, format);
                setlocale(LC_ALL, "");

                wprintf(L" %lc  Error: ", SAD_SMILE);
                vwprintf(w_format, ap);

                va_end(ap);
        }
}

void fatal_error(const char* format, ...)
{
        va_list ap;

        if (format) {
                va_start(ap, format);

                fprintf(stderr, "Error: ");
                vfprintf(stderr, format, ap);

                va_end(ap);
        }

        exit(EXIT_FAILURE);
}
