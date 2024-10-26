cmake_minimum_required(VERSION 3.0)
project(ppm)
set(CMAKE_C_STANDART 99)
set(CMAKE_C_FLAGS "-O3")

add_executable(ppm src/main.c src/ppm.c src/projector.c src/obj.c)
