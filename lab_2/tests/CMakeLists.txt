cmake_minimum_required(VERSION 3.16.3)
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


set(CMAKE_CXX_STANDARD 17)


# LAB 2 tests
add_executable(lab2_test l2_test.cpp
        ../lab2/src/parent.cpp
        ../lab2/include/parent.h
        ../lab2/src/utils.cpp .
        ../lab2/include/utils.h)

target_link_libraries(lab2_test PRIVATE GTest::GTest)
target_include_directories(lab2_test PRIVATE)

add_test(lab2_test lab2_test)

project(tests)
add_executable(child1
        ../lab2/src/child1.cpp
        ../lab2/src/utils.cpp ../lab2/include/utils.h)

target_include_directories(child1 PRIVATE include)

add_executable(child2
        ../lab2/src/child2.cpp
        ../lab2/src/utils.cpp ../lab2/include/utils.h)

target_include_directories(child2 PRIVATE include)