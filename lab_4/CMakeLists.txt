set(CMAKE_C_STANDARD 11)


add_executable(lab4
        main.cpp
        src/parent.cpp
        include/parent.h
        src/utils.cpp include/utils.h)

target_include_directories(lab4 PRIVATE include)

add_executable(4child1
        src/child1.cpp
        src/utils.cpp include/utils.h)

target_include_directories(4child1 PRIVATE include)

add_executable(4child2
        src/child2.cpp
        src/utils.cpp include/utils.h)

target_include_directories(4child2 PRIVATE include)
set(CMAKE_CXX_FLAGS -pthread)
TARGET_LINK_LIBRARIES(lab4 ${Boost_LIBRARIES} rt)
TARGET_LINK_LIBRARIES(4child2 ${Boost_LIBRARIES} rt)
TARGET_LINK_LIBRARIES(4child1 ${Boost_LIBRARIES} rt)
# SET (CMAKE_VERBOSE_MAKEFILE 1)
# target_include_directories(lab4 PRIVATE include -pthread)
# target_include_directories(4child1 PRIVATE include -pthread)
# target_include_directories(4child2 PRIVATE include -pthread)
# # target_link_libraries(lab3 PRIVATE Threads::Threads)
# add_compile_options(-pthread)
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# set(CMAKE_CXX_FLAGS "-lrt")
# target_link_libraries(lab4 PRIVATE librt.so)