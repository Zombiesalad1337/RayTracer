add_library(tuple tuple.cpp)
add_library(vec vec.cpp)
add_library(point point.cpp)
add_library(color color.cpp)
add_library(canvas canvas.cpp)
add_library(projectile projectile.cpp)

add_executable(main main.cpp)

target_link_libraries(vec tuple)
target_link_libraries(point tuple)
target_link_libraries(color tuple)
target_link_libraries(projectile vec point)
target_link_libraries(canvas color)


target_link_libraries(main projectile canvas)
