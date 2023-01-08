set(CMAKE_C_STANDARD 11)

add_executable(lab5
        main2.cpp
        src/lab5_2.cpp
        src/math1.cpp
        src/math2.cpp)

target_include_directories(lab5 PRIVATE include)
add_compile_options(-ldl)
SET(lab5 "${CMAKE_CXX_FLAGS} -ldl")

target_link_libraries(lab5 ${CMAKE_DL_LIBS})

include(GenerateExportHeader)
add_library(lib1 SHARED "src/math1.cpp" "include/math1.h")
generate_export_header(lib1)
target_include_directories(lib1 PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})

include(GenerateExportHeader)
add_library(lib2 SHARED "src/math2.cpp" "include/math2.h")
generate_export_header(lib2)
target_include_directories(lib2 PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})