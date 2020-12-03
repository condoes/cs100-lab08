#include "gtest/gtest.h"
#include "mult_test.hpp"
#include "div_test.hpp"
#include "pow_test.hpp"

int main2(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}