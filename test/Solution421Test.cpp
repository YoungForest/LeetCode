#include "../src/Solution421.cpp"
#include "../src/utils.hpp"
#include "gtest/gtest.h"

namespace {
TEST(Solution421Test, Basic) {
    vector<pair<vector<int>, int>> test_cases = {
        {{3, 10, 5, 25, 2, 8}, 28},
        {{2, 4}, 6}
    };
    for (auto& tc : test_cases) {
        EXPECT_EQ(LeetCode::Solution421().findMaximumXOR(tc.first), tc.second);
    }
}
} // namespace