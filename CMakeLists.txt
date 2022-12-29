cmake_minimum_required(VERSION 3.20)
project(NHF)

set(CMAKE_CXX_STANDARD 14)

add_executable(NHF
        impl/decoder.c
        impl/tree.c
        impl/file_read.c
        main.c)
