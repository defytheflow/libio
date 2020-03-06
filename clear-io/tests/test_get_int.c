#include <stdlib.h>

#include <clear-io.h>

int main(void)
{
        int num, status;

        status = get_int(NULL, &num);

        return (status == 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}
