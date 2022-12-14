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
find_library(glfw glfw3)
find_library(wayland wayland-client)
find_library(x11 X11)

if (x11)
    message("There is math std lib here")
else()
    message("were fucked up")
endif()

add_executable(${PROJECT_NAME} ${HEADERS} ${CFILES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib m)
