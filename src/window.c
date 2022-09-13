#include "../include/lib_led.h"
#include <raylib.h>
#include <string.h>
#include "../include/raygui.h"

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

static int get_event(Vector2 *ball)
{
    if (IsKeyDown(KEY_RIGHT)) ball->x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) ball->x -= 2.0f;
    if (IsKeyDown(KEY_UP)) ball->y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) ball->y += 2.0f;
    return (0);
}

int open_window(window_t *window)
{
    Vector2 ballPosition = {(float)window->width/2, (float)window->height/2};
    Vector2 mouse = GetMousePosition();
    while (!WindowShouldClose()) {
        get_event(&ballPosition);
        BeginDrawing();
            if (GuiButton((Rectangle){ window->width - 170, window->height - 50, 150, 30 }, "Image Export")) printf("weesh\n");

            ClearBackground(GRAY);
            DrawText("move the ball with arrow keys", 10, 10, 20, BLACK);
            DrawCircleV(ballPosition, 50, RED);
        EndDrawing();
    }
    CloseWindow();
    free(window->window_name);
    return 0;
}
