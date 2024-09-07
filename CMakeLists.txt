cmake_minimum_required(VERSION 3.0)
SET(MYCOMPILE_FLAGS "-g")

option(test "build tests" OFF)
message("Start build:")
if(test)
    set(SRC 
        ./src/libs/graph/graph.cpp
        ./src/libs/export/export.cpp
        ./tests/class_tests/class_tests.cpp)
    add_executable(run ./tests/test.cpp)
    target_link_libraries(run gtest gmock pthread)
    message("Build tests.")
else()
    set(SRC 
        ./src/libs/graph/graph.cpp
        ./src/libs/export/export.cpp
        ./src/program.cpp)
    add_executable(run ./src/main.cpp)
    message("Build program.")
endif()
add_library(libs ${SRC})
target_link_libraries(run libs)