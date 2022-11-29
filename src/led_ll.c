#include "../include/lib_led.h"
#include <string.h>

generator_led_t *search_elem(generator_led_t *list, char const *filepath)
{
    if (!filepath)
        return (NULL);
    printf("%s --> %s\n", filepath, list->filename);
    while(list)
        if (strcmp(filepath, list->filename))
            list->next = list;

    return (list);
}

int print_node(generator_led_t *list)
{
    return 0;
}

static int free_led_node(generator_led_t *led)
{
    if (!led)
        return (-1);
    if (led->filename)
        free(led->filename);
    if (led->fptr)
        fclose(led->fptr);
    free(led);
    return (0);
}

int free_led_list(generator_led_t *list)
{
return (0);
}

static generator_led_t *new_led_node(char const *filepath)
{
    generator_led_t *new_node = malloc(sizeof(generator_led_t));

    if (!new_node)
        return (NULL);
    new_node->filename = strdup(filepath);
    new_node->client_arrays = NULL;
    new_node->fptr = NULL;
    new_node->next = NULL;
    if (!new_node->filename) {
        free(new_node);
        return (NULL);
    }
    return (new_node);
}

generator_led_t *add_node(generator_led_t *list, char const *filepath)
{
    generator_led_t *new_node = NULL;

    if (!filepath)
        return (NULL);
    new_node = new_led_node(filepath);
    if (!new_node && !list)
        return (NULL);
    if (!new_node && list) {
        free_led_list(list);
        return (NULL);
    }
    if (!list)
        list = new_node;
    else
        new_node->next = list;
    return (new_node);
}
