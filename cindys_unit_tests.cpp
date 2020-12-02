#include "gtest/gtest.h"
#include "addtests_iterator.hpp"
#include "subtests_iterator.hpp"
#include "optests_iterator.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}