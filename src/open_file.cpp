#include "../include/lib_led.h"

static char *get_date(void)
{
    return ((char *)"DATE");
}

int open_file(char *filename)
{
    if (filename == NULL)
        filename = get_date();
    std::cout << "filename = " << filename << std::endl;
    return (0);
}
