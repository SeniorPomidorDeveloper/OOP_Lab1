cmake_minimum_required(VERSION 3.0)

option(test "build tests" OFF)
message("Start build:")
if(test)
    enable_testing()
    SET(MYCOMPILE_FLAGS "-g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
    set(SRC 
        ./src/libs/graph/graph.cpp
        ./src/libs/export/export.cpp
        ./tests/class_tests/class_tests.cpp
        ./tests/export_tests/export_tests.cpp)
    add_executable(run ./tests/test.cpp)
    target_link_libraries(run gtest gmock pthread)
    message("Build tests.")
    add_custom_command(TARGET run
                       POST_BUILD
                       COMMAND make -f ../makefile -s
                       COMMENT "Start GenCov"
                       USES_TERMINAL)
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
