cmake_minimum_required(VERSION 3.28)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
add_subdirectory(tests)


add_executable(ShoppingList
        List.cpp
        List.h
        Prod.cpp
        Prod.h
        main.cpp)
