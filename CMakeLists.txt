cmake_minimum_required(VERSION 3.28)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

include_directories(.)
add_subdirectory(tests)


add_executable(ShoppingList
        src/List.cpp
        src/List.h
        src/Prod.cpp
        src/Prod.h
        main.cpp
        src/Button.cpp
        src/Button.h
        src/Text.cpp
        src/Text.h
        src/InputManager.cpp
        src/InputManager.h)

target_link_libraries(ShoppingList sfml-system sfml-window sfml-graphics sfml-audio)

