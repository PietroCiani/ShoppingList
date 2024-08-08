project(ShoppingList_tests)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
FetchContent_MakeAvailable(googletest)

add_executable(ShoppingList_tests
        List_tests.cpp
)
target_link_libraries(ShoppingList_tests gtest gtest_main)
