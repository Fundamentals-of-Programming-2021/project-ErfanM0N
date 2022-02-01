cmake_minimum_required(VERSION 3.0.0)
project(FOP_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(FOP_Project main.c)

include_directories("/usr/include/SDL2")
target_link_libraries(FOP_Project m SDL2 SDL2_gfx SDL2_image SDL2_ttf)
