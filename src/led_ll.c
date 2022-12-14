#include "../include/lib_led.h"
#include <string.h>

int search_elem(generator_led_t *list, char const *filepath)
{
    if (!filepath)
        return (1);
    if (!list)
        return (0);
    while(list->next)
        if (strcmp(filepath, list->filename))
            list->next = list;
        else return (0);
    return (1);
}

int print_node(generator_led_t *list)
{
    generator_led_t *tmp = list;

    for (int i = 0; tmp; tmp = tmp->next) {
        printf("%s\n", tmp->filename);
    }
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

generator_led_t *new_led_node(char const *filepath)
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
    if (!new_node)
        return (NULL);
    new_node->next = list;
    return (new_node);
}
