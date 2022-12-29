set(CMAKE_C_STANDARD 11)


add_executable(lab3
        main.cpp
        src/lab.cpp
        include/lab.h)

target_include_directories(lab3 PRIVATE include -pthread)
# target_link_libraries(lab3 PRIVATE Threads::Threads)
add_compile_options(-pthread)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
