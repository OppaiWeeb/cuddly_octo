#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <raylib.h>
#include <time.h>

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

int open_file(char const *filename, generator_led_t *led);
int open_window(window_t *window);
int free_led(generator_led_t *led);
