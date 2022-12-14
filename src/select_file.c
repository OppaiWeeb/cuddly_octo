#include "../include/lib_led.h"
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION

generator_led_t *select_file_update(window_t *window, generator_led_t *list)
{
    FilePathList dropped = {0};

    if (IsFileDropped())
        dropped = LoadDroppedFiles();
    if (dropped.count != 0) {
        for (int i = 0; i < dropped.count; i++)
            if (!search_elem(list, dropped.paths[i])) {
                list = add_node(list, dropped.paths[i]);
                print_node(list);
            }
    }
    UnloadDroppedFiles(dropped);
    return (list);
}
