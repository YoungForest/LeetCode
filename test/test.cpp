#include "../src/utils.hpp"
#include "gtest/gtest.h"

namespace {

TEST(BoolToString, General) { EXPECT_EQ(boolToString(true), "True"); }

} // namespace