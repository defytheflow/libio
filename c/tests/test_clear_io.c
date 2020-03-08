#include <clear-io.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_get_string(void);
int test_get_int(void);
int test_get_float(void);

int main(int argc, char** argv)
{
        char* test_function;

        if (argc == 0) {
                fprintf(stderr, "Usage: test_clear_io <test_function>\n");
                return 1;
        }

        test_function = argv[1];

        if (strcmp(test_function , "get_string") == 0)
                return test_get_string();
        else if (strcmp(test_function, "get_int") == 0)
                return test_get_int();
        else if (strcmp(test_function, "get_float") == 0)
                return test_get_float();
        else {
                fprintf(stderr, "Error: unknown <test_function> %s\n",
                        test_function);
                return 1;
        }

        return 0;
}

int test_get_string(void)
{
        int len;
        char string[256];

        len = get_string(NULL, string, sizeof(string));

        return (len == 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

int test_get_int(void)
{
        int num, status;

        status = get_int(NULL, &num);

        return (status == 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int test_get_float(void)
{
        float num, status;

        status = get_float(NULL, &num);

        return (status == 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}
