set(TEST_SOURCES
    test.cpp
)

add_executable(tests ${TEST_SOURCES})

# Link against the necessary libraries
target_link_libraries(tests PRIVATE
    GTest::gtest
    GTest::gtest_main
    ${GET_DATA_LIBRARY}
    ${FILE_DIALOG}
)

# Register the test
add_test(NAME AllTests COMMAND tests)
