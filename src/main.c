#include "../include/lib_led.h"

int main (int argc, char *argv[])
{
    generator_led_t led;
    window_t *window = init_window();
    if (argc > 2) {
        printf("Usage %s <filename>\n", argv[0]);
        return (1);
    }
    led.fptr = open_file(argv[1]);
    if (led.fptr == NULL)
        return (-1);
    open_window(window);
    fclose(led.fptr);
    return 0;
}
