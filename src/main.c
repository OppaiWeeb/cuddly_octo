#include "../include/lib_led.h"
#include <stdlib.h>

static window_t *init_window(void)
{
    struct window_s *window = malloc(sizeof(window_t));
    if (!window)
        return (NULL);

    window->width = 800;
    window->height = 420;
    window->window_name = strdup("Cuddly Octo");
    InitWindow(window->width, window->height, window->window_name);
    SetTargetFPS(60);
    return (window);
}

static generator_led_t *generate_led(char *const filename)
{
    generator_led_t *led = malloc(sizeof(generator_led_t));
    int ret = 0;

    if (!led)
        return (NULL);
    ret = open_file(filename, led);
    if (ret) {
        free_led(led);
        return (NULL);
    }
    return (led);
}

int main (int argc, char *argv[])
{
    generator_led_t *led = NULL;
    window_t *window = NULL;

    if (argc > 2) {
        printf("Usage %s <filename>\n", argv[0]);
        return (1);
    }
    led = generate_led(argv[1]);
    if (!led)
        return (-1);
    if (!led->fptr)
        return (-2);
    window = init_window();
    if (!window)
        free_led(led);
    open_window(window);
    free_led(led);
    return (0);
}
