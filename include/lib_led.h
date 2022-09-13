#ifndef _LIB_LED_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <raylib.h>
#include <time.h>
#include "raygui.h"

#define RAYGUI_IMPLEMENTATION

typedef struct client_s
{
    char id;
    char nb_led;
    char *arrays_led;
} client_t;

typedef struct window_s
{
    int width;
    int height;
    char *window_name;
} window_t;

typedef struct generator_led
{
    char *filename;
    FILE *fptr;
    client_t *client_arrays;
} generator_led_t;

FILE *open_file(char *filename);
int open_window(window_t *window);
window_t *init_window(void);

#endif // !_LIB_LED_H_
