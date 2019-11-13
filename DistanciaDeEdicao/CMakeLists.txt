cmake_minimum_required(VERSION 3.15)
project(DistanciaDeEdicao C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DistanciaDeEdicao
        main.c
        TAD_de.c
        TAD_de.h)
