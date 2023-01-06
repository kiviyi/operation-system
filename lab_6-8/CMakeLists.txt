set(CMAKE_C_STANDARD 11)


add_executable(control
        include/control.cpp
        src/topology.hpp
        src/zmq_std.hpp)

add_executable(calculation
        include/calculation_node.cpp
        src/zmq_std.hpp
        include/search.cpp
        src/search.hpp)

# target_include_directories(control PRIVATE include -pthread)
# target_include_directories(calculation PRIVATE include -pthread)
# target_include_directories(control PRIVATE include -lzmq)
# target_include_directories(calculation PRIVATE include -lzmq)


# # target_link_libraries(lab3 PRIVATE Threads::Threads)
# add_compile_options(-pthread)
# add_compile_options(-lzmq)
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lzmq")
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
SET (CMAKE_VERBOSE_MAKEFILE 1)
TARGET_LINK_LIBRARIES(control ${Boost_LIBRARIES} zmq)
TARGET_LINK_LIBRARIES(calculation ${Boost_LIBRARIES} zmq)

TARGET_LINK_LIBRARIES(control ${Boost_LIBRARIES} pthread)
TARGET_LINK_LIBRARIES(calculation ${Boost_LIBRARIES} pthread)