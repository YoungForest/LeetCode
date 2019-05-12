#pragma once
#include "pch.h"
#include <queue>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution199
{
public:
	Solution199();
	~Solution199();
	vector<int> rightSideView(shared_ptr<TreeNode> root) {
		queue<shared_ptr<TreeNode>> q;
		vector<int> ret;
		if (root) q.push(root);
		while (!q.empty()) {
			int s = q.size();
			shared_ptr<TreeNode> current = nullptr;
			for (int i = 0; i < s; ++i) {
				current = q.front();
				q.pop();
				if (current->left) q.push(current->left);
				if (current->right) q.push(current->right);
			}
			ret.push_back(current->val);
		}

		return ret;
	}
};

