#include <safeio.h>

#include <stdlib.h>

int main(void)
{
        float num, status;

        status = get_float(&num);

        return (status == 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}
