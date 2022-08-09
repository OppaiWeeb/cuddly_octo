cmake_minimum_required(VERSION 3.20)
project(led_generator)
find_library(RAYLIB raylib)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SRCS ./src/*)
file(GLOB_RECURSE HEADER ./include/*)

add_executable(${PROJECT_NAME} ${SRCS} ${HEADER})
target_link_libraries(${CMAKE_PROJECT_NAME} ${RAYLIB})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -O3 -Wall -Wextra -fanalyzer")
