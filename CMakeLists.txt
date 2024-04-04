cmake_minimum_required(VERSION 3.27)
project(farmacie)

set(CMAKE_CXX_STANDARD 23)

add_executable(farmacie main.cpp)

target_compile_options(farmacie PRIVATE -Wall -Wextra -Wpedantic -Werror)
