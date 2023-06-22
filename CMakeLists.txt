cmake_minimum_required(VERSION 3.22)
project(RayTracerChallenge)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12 -L /usr/lib/gcc/x86_64-linux-gnu/12 -Wall -Wextra -lstdc++fs -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

message(STATUS "PROJECT SOURCE DIR : ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)


include(CTest)

enable_testing()

add_subdirectory(tests)


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


