#include <cleario.h>

#include <stdlib.h>

int main(void)
{
        int len;
        char string[256];

        len = get_string(string, sizeof(string));

        return (len == 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
