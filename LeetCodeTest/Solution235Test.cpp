#include "pch.h"
#include "../LeetCode/Solution235.hpp"
#include "../LeetCode/pch.h"
#include "../LeetCode/pch.cpp"

TEST(Solution235Test, Correct) {
	vector<string> test_cases = {
		"[6,2,8,0,4,7,9,null,null,3,5]"
	};
	for (const auto& test_case : test_cases) {
		auto root = stringToTreeNode(test_case);
		EXPECT_EQ(root, Solution235().lowestCommonAncestor(root, root->left, root->right));
	}
}