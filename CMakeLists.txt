cmake_minimum_required(VERSION 3.20)
project(led_generator)
find_library(RAYLIB raylib)

set(MATH m)
set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SRCS ./src/*)
file(GLOB_RECURSE HEADER ./include/*)

add_executable(${PROJECT_NAME} ${SRCS} ${HEADER})
target_link_libraries(${CMAKE_PROJECT_NAME} ${RAYLIB})
target_link_libraries(${CMAKE_PROJECT_NAME} ${MATH})

set(CMAKE_CFLAGS "${CMAKE_CFLAGS} -Ofast -O3 -Wall -Wextra -fanalyzer")
