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
add_executable(lab5_test
        l5_2_test.cpp
        ../src/lab5_2.cpp
        ../src/math1.cpp
        ../src/math2.cpp)

target_link_libraries(lab5_test PRIVATE GTest::GTest)
target_include_directories(lab5_test PRIVATE)

add_test(lab5_test lab5_test)

project(tests)
# add_compile_options(-pthread)
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# target_include_directories(lab5_test PRIVATE include)
add_compile_options(-ldl)
SET(lab5_test "${CMAKE_CXX_FLAGS} -ldl")

target_link_libraries(lab5_test PRIVATE ${CMAKE_DL_LIBS})

include(GenerateExportHeader)
add_library(lib1 SHARED "../src/math1.cpp" "../include/math1.h")
generate_export_header(lib1)
target_include_directories(lib1 PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})

include(GenerateExportHeader)
add_library(lib2 SHARED "../src/math2.cpp" "../include/math2.h")
generate_export_header(lib2)
target_include_directories(lib2 PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})