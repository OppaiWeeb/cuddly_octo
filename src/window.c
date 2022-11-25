#define RAYGUI_IMPLEMENTATION
#include "../include/lib_led.h"
#include "../sub/raygui/src/raygui.h"
#include <raylib.h>

window_t *init_window(void)
{
    struct window_s *window = malloc(sizeof(window_t));
    if (!window)
        return (NULL);

    window->width = 800;
    window->height = 420;
    window->window_name = strdup("Led generator");
    InitWindow(window->width, window->height, window->window_name);
    SetTargetFPS(60);
    return (window);
}

static int print_text(bool *press, unsigned int time)
{
    if (*press && time >= 500)
        *press = 0;
    DrawText("JE SUIS UN TEXT", 100, 50, 25, GREEN);
    return (0);
}

int open_window(window_t *window)
{
    Vector2 mouse = GetMousePosition();
    bool press = 0;
    char button_pressed = 0;
    unsigned int time = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
            if (GuiButton((Rectangle){ window->width - 170, window->height - 50, 150, 30 }, "press_me")) {
                press = 1;
                time = 0;
            }
            print_text(&press, time);
            ClearBackground(GRAY);
        EndDrawing();
    }
    CloseWindow();
    free(window->window_name);
    return 0;
}
