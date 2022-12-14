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
    execute_process(COMMAND bash -c "objdump -tC /usr/local/lib/libraylib.a | grep rglfw" OUTPUT_VARIABLE var)
    message("This is ${var}")
else()
    message("were fucked up")
endif()

if (NOT var)
    message("TOTO IS NOT HERE")
endif()
add_executable(${PROJECT_NAME} ${HEADERS} ${CFILES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib m)
