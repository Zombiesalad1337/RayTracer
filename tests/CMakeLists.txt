
set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(tuple_test_exec tuple_test.cpp)
add_executable(vec_test_exec vec_test.cpp)
add_executable(color_test_exec color_test.cpp)
add_executable(canvas_test_exec canvas_test.cpp)
add_executable(matrix_test_exec matrix_test.cpp)
add_executable(ray_test_exec ray_test.cpp)
add_executable(intersect_test_exec intersect_test.cpp)
add_executable(shape_test_exec shape_test.cpp)
add_executable(sphere_test_exec sphere_test.cpp)
add_executable(point_light_test_exec point_light_test.cpp)
add_executable(material_test_exec material_test.cpp)
add_executable(lighting_test_exec lighting_test.cpp)
add_executable(world_test_exec world_test.cpp)
add_executable(computation_test_exec computation_test.cpp)
add_executable(camera_test_exec camera_test.cpp)
add_executable(plane_test_exec plane_test.cpp)

add_library(tuple_test tuple_test.cpp)
add_library(vec_test vec_test.cpp)
add_library(color_test color_test.cpp)
add_library(canvas_test canvas_test.cpp)
add_library(matrix_test matrix_test.cpp)
add_library(ray_test ray_test.cpp)
add_library(intersect_test intersect_test.cpp)
add_library(shape_test shape_test.cpp)
add_library(sphere_test sphere_test.cpp)
add_library(point_light_test point_light_test.cpp)
add_library(material_test material_test.cpp)
add_library(lighting_test lighting_test.cpp)
add_library(world_test world_test.cpp)
add_library(computation_test computation_test.cpp)
add_library(camera_test camera_test.cpp)
add_library(plane_test plane_test.cpp)

target_include_directories(tuple_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(vec_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(color_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(canvas_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(matrix_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(ray_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(intersect_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(shape_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(sphere_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(point_light_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(material_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(lighting_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(world_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(computation_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(camera_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(plane_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)


target_link_libraries(tuple_test_exec
                        tuple
                        vec
                        point
                        GTest::gtest_main
)

target_link_libraries(vec_test_exec tuple
                        vec
                        point
                        GTest::gtest_main
)

target_link_libraries(color_test_exec
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(canvas_test_exec
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(matrix_test_exec
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)

target_link_libraries(ray_test_exec
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(intersect_test_exec
                        intersection
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(shape_test_exec
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(sphere_test_exec
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(plane_test_exec
                        plane 
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)

target_link_libraries(point_light_test_exec
                        point_light
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(material_test_exec
                        material
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(lighting_test_exec
                       lighting 
                       material
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(world_test_exec
                       world 
                       camera
                       computation
                       lighting
                       material
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(computation_test_exec
                       computation 
                       lighting
                       material
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
target_link_libraries(camera_test_exec
                       camera 
                       lighting
                       material
                        sphere
                        shape
                        ray
                        matrix
                        canvas
                        color
                        tuple
                        vec
                        point
                        GTest::gtest_main
)
add_test(
    NAME tuple_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/tuple_test_exec
    )

add_test(
    NAME vec_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/vec_test_exec
    )
add_test(
    NAME color_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/color_test_exec
    )
add_test(
    NAME canvas_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/canvas_test_exec
    )
add_test(
    NAME matrix_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/matrix_test_exec
    )
add_test(
    NAME ray_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/ray_test_exec
    )
add_test(
    NAME intersect_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/intersect_test_exec
    )
add_test(
    NAME shape_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/shape_test_exec
    )
add_test(
    NAME sphere_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/sphere_test_exec
    )
add_test(
    NAME point_light_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/point_light_test_exec
    )
add_test(
    NAME material_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/material_test_exec
    )
add_test(
    NAME lighting_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/lighting_test_exec
    )
add_test(
    NAME world_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/world_test_exec
    )
add_test(
    NAME computation_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/computation_test_exec
    )
add_test(
    NAME camera_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/camera_test_exec
    )
add_test(
    NAME plane_test_exec
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/plane_test_exec
    )
