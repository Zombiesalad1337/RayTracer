add_library(try try.cpp)

add_executable(main main.cpp)

target_link_libraries(main try)
