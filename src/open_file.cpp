#include "../include/lib_led.h"

static char *get_date(void)
{
    std::time_t now = std::time(nullptr);
    char *date = std::ctime(&now);

    std::strftime(date, strlen(date), "%d_%b_%H_%M", localtime(&now));
    return (date);
}

int open_file(char *filename)
{
    if (filename == NULL)
        filename = get_date();
    std::cout << "filename = " << filename << std::endl;
    return (0);
}
