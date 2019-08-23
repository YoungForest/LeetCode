#include "gtest/gtest.h"
#include "../src/MorrisTraversal.cpp"

namespace {
    TEST(MorrisTraversal, Correct) {
        auto input = stringToTreeNode("[1,2,3,4,5]");
        vector<int> expect {4,2,5,1,3};
        EXPECT_EQ(expect, MorrisTraversal(input));
    }
}