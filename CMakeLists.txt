cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-g3")

project(Cuddly_Octo)
FILE(GLOB CFILES
    src/led_ll.c
    src/main.c
    src/openfile.c
    src/select_file.c
    src/window.c)

FILE(GLOB HEADERS
    include/lib_led.h
    include/raylib.h)

find_library(math m)
find_library(raylib raylib)
find_library(glfw glfw)
find_library(wayland wayland-client)
find_library(x11 X11)

if (NOT math)
    message("No Math")
endif()

if (NOT wayland)
    message("NO wayland")
    if (NOT X11)
        message("No X11")
    endif()
endif()

if (NOT raylib)
    message("NO raylib")
endif()



execute_process(COMMAND bash -c "objdump -tC /usr/local/lib/libraylib.a | grep rglfw" OUTPUT_VARIABLE var)
if (var)
    message("GLFW no need at compile")
else()
    message("GLFW need at compile")
    if (NOT glfw)
        message("FUUUUCK")
    endif()
endif()

add_executable(${PROJECT_NAME} ${HEADERS} ${CFILES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib m)
