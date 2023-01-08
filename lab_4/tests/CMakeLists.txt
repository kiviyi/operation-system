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

# LAB 4 tests
add_executable(lab4_test lab4_test.cpp
        ../src/parent.cpp
        ../include/parent.h
        ../src/utils.cpp .
        ../include/utils.h)

target_link_libraries(lab4_test PRIVATE GTest::GTest)
target_include_directories(lab4_test PRIVATE ../include)

add_test(lab4_test lab4_test)
add_executable(4child1
        ../src/child1.cpp
        ../src/utils.cpp ../include/utils.h)

target_include_directories(4child1 PRIVATE include)

add_executable(4child2
        ../src/child2.cpp
        ../src/utils.cpp ../include/utils.h)

target_include_directories(4child2 PRIVATE include)
set(CMAKE_CXX_FLAGS -pthread)
TARGET_LINK_LIBRARIES(lab4_test PRIVATE ${Boost_LIBRARIES} rt)
TARGET_LINK_LIBRARIES(4child2 PRIVATE ${Boost_LIBRARIES} rt)
TARGET_LINK_LIBRARIES(4child1 PRIVATE ${Boost_LIBRARIES} rt)

project(tests)