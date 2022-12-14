#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <raylib.h>

typedef struct client_s {
    char id;
    char nb_led;
    char *arrays_led;
} client_t;

enum SCENE {
    SELECT_FILE = 0,
    WORK_ON_FILE,
    END_AND_SAVE,
};

typedef struct window_s {
    int width;
    int height;
    char *window_name;
    enum SCENE scene;
} window_t;

typedef struct generator_led {
    char *filename;
    FILE *fptr;
    client_t *client_arrays;
    struct generator_led *next;
} generator_led_t;

int open_file(char const *filename, generator_led_t *led);
int open_window(window_t *window);
int free_led_list(generator_led_t *led);

generator_led_t *select_file_update(window_t *window, generator_led_t *list);
generator_led_t *add_node(generator_led_t *list, char const *filepath);
generator_led_t *new_led_node(char const *filepath);
int search_elem(generator_led_t *list, char const *filepath);
int print_node(generator_led_t *list);


int work_on_file_update();
int end_and_save_update();
int select_file_window();
int work_on_file_window();
int end_and_save_window();
