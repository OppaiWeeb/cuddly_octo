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

add_executable(${PROJECT_NAME} ${HEADERS} ${CFILES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib m)
