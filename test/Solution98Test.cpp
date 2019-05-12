#include "../src/Solution98.cpp"
#include "../src/utils.hpp"
#include "gtest/gtest.h"

namespace {
TEST(Solution98Test, SmallCases) {
    vector<pair<string, bool>> test_cases = {
        {"[2, 1, 3]", true},
        {"[1, 1]", false},
        {"[5, 1, 4, null, null, 3, 6]", false}};
    for (auto &test_case : test_cases) {
        EXPECT_EQ(LeetCode::Solution98().isValidBST(
                      stringToTreeNode(test_case.first)),
                  test_case.second);
    }
}
} // namespace