add_subdirectory(/usr/src/gtest/ ${EXECUTABLE_OUTPUT_PATH}/gtest)

set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(tuple_test_exec tuple_test.cpp)
add_executable(vec_test_exec vec_test.cpp)
add_executable(color_test_exec color_test.cpp)
add_executable(canvas_test_exec canvas_test.cpp)

add_library(tuple_test tuple_test.cpp)
add_library(vec_test vec_test.cpp)
add_library(color_test color_test.cpp)
add_library(canvas_test canvas_test.cpp)

target_include_directories(tuple_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(vec_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(color_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(canvas_test_exec PRIVATE ${PROJECT_SOURCE_DIR}/src)


target_link_libraries(tuple_test_exec
                        tuple
                        vec
                        point
                        gtest gtest_main
)

target_link_libraries(vec_test_exec
                        tuple
                        vec
                        point
                        gtest gtest_main
)
target_link_libraries(color_test_exec
                        color
                        tuple
                        vec
                        point
                        gtest gtest_main
)
target_link_libraries(canvas_test_exec
                        canvas
                        color
                        tuple
                        vec
                        point
                        gtest gtest_main
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
