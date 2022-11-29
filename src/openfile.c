#include "../include/lib_led.h"

static char *get_date(void)
{
    time_t now = time(NULL);
    char *date = ctime(&now);

    strftime(date, strlen(date), "%d_%b_%H_%M", localtime(&now));
    return (date);
}

static FILE *check_file_state(char *filename)
{
    FILE *tmp = fopen(filename, "rb+");

    if (tmp == NULL) {
        printf("The File %s doesn't exist\nCreating File in progress\n", filename);
        if ((tmp = fopen(filename, "wb+")) == NULL) {
            printf("Error while Creating File\n");
            return (NULL);
        }
    }
    return (tmp);
}

int open_file(char const *filepath, generator_led_t *led)
{
    char *filename = NULL;

    if (filepath == NULL)
        filename = get_date();
    strcat(filename, ".led");
    led->filename = strdup(filename);
    led->fptr = check_file_state(led->filename);
    if (led->fptr == NULL)
        return (-1);
    return (0);
}
