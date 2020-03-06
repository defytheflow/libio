#include <cleario.h>

#include <stdlib.h>

int main(void)
{
        float num, status;

        status = get_float(NULL, &num);

        return (status == 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}
