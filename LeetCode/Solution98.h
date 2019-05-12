#pragma once

#include "pch.h"

class Solution98
{
public:
	Solution98();
	~Solution98();
private:
	tuple<bool, int, int> recurse(shared_ptr<TreeNode> root) {
		// 是否是二叉查找树，子树最大值，子树最小值
		tuple<bool, int, int> ret = { true, root->val, root->val };
		if (root->left) {
			auto l = recurse(root->left);
			if (get<0>(l) == false)
				return { false, 0, 0 };
			else {
				if (root->val <= get<1>(l))
					return { false, 0, 0 };
				get<2>(ret) = get<2>(l);
			}
		}
		if (root->right) {
			auto r = recurse(root->right);
			if (get<0>(r) == false)
				return { false, 0, 0 };
			else {
				if (root->val >= get<2>(r))
					return { false, 0, 0 };
				get<1>(ret) = get<1>(r);
			}
		}
		return ret;
	}
public:
	bool isValidBST(shared_ptr<TreeNode> root) {
		// 由于二叉查找树本身就是递归定义的，所以通过递归判断也是自然而然的想法
		if (root == nullptr) return true;
		auto ret = recurse(root);
		return get<0>(ret);
	}
};

