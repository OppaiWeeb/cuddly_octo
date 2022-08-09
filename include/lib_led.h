#ifndef _LIB_LED_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <raylib.h>
#include <time.h>

typedef struct rgb_s
{
    char r;
    char g;
    char b;
} rgb_t;

typedef struct client_s
{
    char id;
    char nb_led;
} client_t;

typedef struct window_s
{
    int width;
    int height;
    char *window_name;

} window_t;

char *open_file(char *filename);
int open_window(void);

#endif // !_LIB_LED_H_
