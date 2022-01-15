cmake_minimum_required(VERSION 3.20)
project(NHF)

set(CMAKE_CXX_STANDARD 14)

add_executable(NHF
        decoder.c
        tree.c
        file_read.c
        main.c)
