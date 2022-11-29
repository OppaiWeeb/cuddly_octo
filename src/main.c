#include "../include/lib_led.h"

static window_t *init_window(void)
{
    struct window_s *window = malloc(sizeof(window_t));
    if (!window)
        return (NULL);

    window->width = 800;
    window->height = 420;
    window->window_name = strdup("Cuddly Octo");
    window->scene = SELECT_FILE;
    InitWindow(window->width, window->height, window->window_name);
    SetTargetFPS(60);
    return (window);
}

int main(int argc, char *argv[])
{
    window_t *window = NULL;

    if (argc > 1) {
        printf("Usage %s\n", argv[0]);
        return (1);
    }
    window = init_window();
    if (!window)
        return (-1);
    open_window(window);
    return (0);
}
