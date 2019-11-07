cmake_minimum_required(VERSION 3.15)
project(Tarefa_A)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tarefa_A
        a.out
        arq1.txt
        arq2.txt
        arq3.txt
        arqAleatorio.txt
        main.c
        Piramide.c
        Piramide.h)
