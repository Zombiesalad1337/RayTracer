add_subdirectory(/usr/src/gtest/ ${EXECUTABLE_OUTPUT_PATH}/gtest)

set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(${TEST_BINARY} tuple_test.cpp)

add_library(TEST_BINARY tuple_test.cpp)

target_include_directories(TEST_BINARY PRIVATE ${PROJECT_SOURCE_DIR}/src)


target_link_libraries(${TEST_BINARY}
                        tuple
                        gtest gtest_main
)

add_test(
    NAME ${TEST_BINARY}
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY}
    )
