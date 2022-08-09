#include "../include/lib_led.h"

int main (int argc, char *argv[])
{
    if (argc > 2) {
        std::cout << "Usage: "<< argv[0] << " <filename>" << std::endl;
        return (1);
    }
    open_file(argv[1]);
    return 0;
}

