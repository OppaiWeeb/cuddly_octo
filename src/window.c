#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#define RAYGUI_IMPLEMENTATION
#include "../include/lib_led.h"
#include "../include/raygui.h"

static generator_led_t *update(window_t *window, generator_led_t *list)
{
    switch (window->scene) {
        case SELECT_FILE:
            list = select_file_update(window, list);
            break;
        case WORK_ON_FILE:
            work_on_file_update();
            if (GuiButton((Rectangle){50, 180, window->width/5, window->height/4}, "Press me to save")) {
                window->scene++;
            }
            break;
        case END_AND_SAVE:
            end_and_save_update();
            if (GuiButton((Rectangle){50, 180, window->width/5, window->height/4}, "Press me to open file")) {
                window->scene = SELECT_FILE;
            }
            break;
    }
    return (list);
}

static int draw(window_t *window)
{
    BeginDrawing();
    switch (window->scene) {
        case SELECT_FILE:
            select_file_window();
            ClearBackground(RED);
            break;
        case WORK_ON_FILE:
            work_on_file_window();
            ClearBackground(GREEN);
            break;
        case END_AND_SAVE:
            end_and_save_window();
            ClearBackground(WHITE);
            break;
    }
    EndDrawing();
    return (0);
}

int work_on_file_update(void){return 0;}
int end_and_save_update(void){return 0;}

int select_file_window(void){return 0;}
int work_on_file_window(void){return 0;}
int end_and_save_window(void){return 0;}

int open_window(window_t *window)
{
    generator_led_t *list = NULL;

    while (!WindowShouldClose()) {
        list = update(window, list);
        draw(window);
    }
    CloseWindow();
    free(window->window_name);
    return 0;
}
