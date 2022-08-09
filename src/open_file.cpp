#include "../include/lib_led.h"
#include <chrono>

static char *get_date(void)
{
    std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << "date = " << std::ctime(&date) << std::endl;
    return ((char *)"DATE");
}

int open_file(char *filename)
{
    if (filename == NULL)
        filename = get_date();
    std::cout << "filename = " << filename << std::endl;
    return (0);
}
