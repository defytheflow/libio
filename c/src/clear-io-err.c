#include <clear-io-err.h>

#include <locale.h>  // setlocale()
#include <stdarg.h>  // va_list, va_start(), va_end()
#include <stdio.h>   // *printf()
#include <stdlib.h>  // mbstowcs(), exit(), EXIT_FAILURE
#include <string.h>  // strlen()
#include <wchar.h>   // wchar_t, fwide()

#define SAD_SMILE L'\u2639'

void simple_error(const char* format, ...)
{
        int stream_orientation;
        va_list ap;
        wchar_t w_format[strlen(format) + 1];

        if (format) {
                va_start(ap, format);
                stream_orientation = fwide(stderr, 0);

                if (stream_orientation < 0) {           // byte orientation
                        fprintf(stderr, "Error: ");
                        vfprintf(stderr, format, ap);
                } else if (stream_orientation > 0) {    // wide orientation
                        mbstowcs(w_format, format, sizeof(w_format));
                        fwprintf(stderr, L"Error: ");
                        vfwprintf(stderr, w_format, ap);
                } else {                                // no orientation
                        fprintf(stderr, "Error: ");
                        vfprintf(stderr, format, ap);
                }

                va_end(ap);
        }
}

void smile_error(const char* format, ...)
{
        int stream_orientation;
        va_list ap;
        wchar_t w_format[strlen(format) + 1];

        if (format) {
                va_start(ap, format);
                stream_orientation = fwide(stderr, 0);

                setlocale(LC_ALL, "");

                if (stream_orientation < 0) {           // byte orientation
                        fprintf(stderr, " :( Error: ");
                        vfprintf(stderr, format, ap);
                } else if (stream_orientation > 0) {    // wide orientation
                        mbstowcs(w_format, format, sizeof(w_format));
                        fwprintf(stderr, L" %lc  Error: ", SAD_SMILE);
                        vfwprintf(stderr, w_format, ap);
                } else {                                // no orientation
                        mbstowcs(w_format, format, sizeof(w_format));
                        fwprintf(stderr, L" %lc  Error: ", SAD_SMILE);
                        vfwprintf(stderr, w_format, ap);
                }

                va_end(ap);
        }
}

void fatal_error(const char* format, ...)
{
        int stream_orientation;
        va_list ap;
        wchar_t w_format[strlen(format) + 1];

        if (format) {
                va_start(ap, format);
                stream_orientation = fwide(stderr, 0);

                if (stream_orientation < 0) {            // byte orientation
                        fprintf(stderr, "Error: ");
                        vfprintf(stderr, format, ap);
                } else if (stream_orientation > 0) {     // wide orientation
                        mbstowcs(w_format, format, sizeof(w_format));
                        fwprintf(stderr, L"Error: ");
                        vfwprintf(stderr, w_format, ap);
                } else {                                 // no orientation
                        fprintf(stderr, "Error: ");
                        vfprintf(stderr, format, ap);
                }

                va_end(ap);
        }

        exit(EXIT_FAILURE);
}
