cmake_minimum_required(VERSION 3.27)
project(farmacie)

set(CMAKE_CXX_STANDARD 23)

add_executable(farmacie main.cpp
        medicine.cpp
        medicine.h
        test_medicine.cpp
        test_medicine.h
        my_list.h
        repository_medicine.cpp
        repository_medicine.h
        test_repository_medicine.cpp
        test_repository_medicine.h
        service_medicine.cpp
        service_medicine.h
        test_service_medicine.cpp
        test_service_medicine.h
        ui.cpp
        ui.h)

target_compile_options(farmacie PRIVATE -Wall -Wextra -Wpedantic -Werror)
