#include "../include/lib_led.h"

int main (int argc, char *argv[])
{
    char *filename = NULL;
    if (argc > 2) {
        printf("Usage %s <filename>\n", argv[0]);
        return (1);
    }
    filename = open_file(argv[1]);
    open_window();
    free(filename);
    return 0;
}

