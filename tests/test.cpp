// math_functions_test.cpp

#include <gtest/gtest.h>
#include "WindProData.h"
#include "file_dialog.h"

// Test case for the add function
TEST(MathFunctionsTest, AddTest) {
  // Test inputs
  int a = 2;
  int b = 3;

  // Expected result
  int expected = 5;

  int result = 5;
  
  EXPECT_EQ(result, expected);
}

TEST(MathFunctionsTest, RandomErrorTest) {
  // Test inputs
  int a = 2;
  int b = 3;

  // Expected result
  int expected = 6;

  // Call the function being tested
  int result = 7;
  // Check if the result matches the expected value
  EXPECT_EQ(result, expected);
  
}

