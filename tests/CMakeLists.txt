add_subdirectory(/usr/src/gtest/ ${EXECUTABLE_OUTPUT_PATH}/gtest)

set(TEST_BINARY ${PROJECT_NAME}_test)


add_executable(${TEST_BINARY} test_try.cpp)

target_link_libraries(${TEST_BINARY}
                        try 
                        gtest gtest_main
)

add_test(
    NAME ${TEST_BINARY}
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY}
    )
