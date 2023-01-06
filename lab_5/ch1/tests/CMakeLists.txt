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
add_executable(lab5_test l5_1_test.cpp
        ../src/lab5_1.cpp
        ../include/lab5_1.h
        ../src/math1.cpp
        ../include/math1.h)
        

target_link_libraries(lab5_test PRIVATE GTest::GTest)
target_include_directories(lab5_test PRIVATE)

add_test(lab5_test lab5_test)

project(tests)
# add_compile_options(-pthread)
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")