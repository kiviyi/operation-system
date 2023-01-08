set(CMAKE_C_STANDARD 11)


add_executable(lab5
        main1.cpp
        src/lab5_1.cpp
        include/lab5_1.h
        src/math1.cpp
        include/math1.h)

# target_include_directories(lab3 PRIVATE include -pthread)
target_include_directories(lab5 PRIVATE include)
