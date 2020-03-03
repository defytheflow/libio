#include <safeio.h>

#include <stdlib.h>

int main(void)
{
        int num, status;

        status = get_int(&num);

        return (status == 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}
