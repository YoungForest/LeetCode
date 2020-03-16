#include "../src/Solution1238.cpp"
#include "../src/utils.hpp"
#include "gtest/gtest.h"

namespace {
TEST(Solution1238Test, Basic) {
    vector<pair<int, int>> test_cases = {{2, 3}, {3, 2}};
    for (auto &tc : test_cases) {
        auto s = LeetCode::Solution1238();
        auto ret = s.circularPermutation(tc.first, tc.second);
        ASSERT_EQ(ret.size(), 1 << tc.first);
        for (size_t i = 0; i + 1 < ret.size(); ++i) {
            EXPECT_EQ(s.isAdjacent(ret[i], ret[i + 1]), true);
        }
        EXPECT_EQ(s.isAdjacent(ret.front(), ret.back()), true);
    }
}
} // namespace