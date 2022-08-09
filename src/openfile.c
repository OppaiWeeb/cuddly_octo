#include "../include/lib_led.h"

static char *get_date(void)
{
    time_t now = time(NULL);
    char *date = ctime(&now);

    strftime(date, strlen(date), "%d_%b_%H_%M", localtime(&now));
    return (date);
}

char *open_file(char *filename)
{
    if (filename == NULL)
        filename = get_date();
    strcat(filename, ".led");
    printf("filename = %s\n", filename);
    return (0);
}
