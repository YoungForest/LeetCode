#include "../src/Solution235.cpp"
#include "../src/utils.hpp"
#include "gtest/gtest.h"

namespace {
TEST(Solution235Test, Correct) {
    vector<string> test_cases = {"[6,2,8,0,4,7,9,null,null,3,5]"};
    for (const auto &test_case : test_cases) {
        auto root = stringToTreeNode(test_case);
        EXPECT_EQ(root, LeetCode::Solution235().lowestCommonAncestor(
                            root, root->left, root->right));
    }
}
} // namespace