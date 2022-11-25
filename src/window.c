#include <stdbool.h>
#define RAYGUI_IMPLEMENTATION
#include "../include/lib_led.h"
#include "../sub/raygui/src/raygui.h"
#include <raylib.h>

static int update(window_t *window, bool *rect)
{
    if (GuiButton((Rectangle){50, 180, window->width/5, window->height/4}, "Press me"))
        *rect = !*rect;

    return (0);
}

int open_window(window_t *window)
{
    bool rectpress = false;
    Rectangle rect = {10, 40, 50 ,50};

    while (!WindowShouldClose()) {
        update(window, &rectpress);
        BeginDrawing();
            ClearBackground(GRAY);
        if (rectpress)
            DrawRectangleRec(rect, RED);
        EndDrawing();
    }
    CloseWindow();
    free(window->window_name);
    return 0;
}
