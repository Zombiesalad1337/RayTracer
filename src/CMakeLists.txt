add_library(tuple tuple.cpp)
add_library(vec vec.cpp)
add_library(point point.cpp)

add_executable(main main.cpp)

target_link_libraries(main tuple vec point)
