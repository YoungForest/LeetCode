#pragma once

#include "utils.hpp"
namespace LeetCode {

class Solution235 {
  public:
    Solution235();
    ~Solution235();
    shared_ptr<TreeNode> lowestCommonAncestor(shared_ptr<TreeNode> root,
                                              shared_ptr<TreeNode> p,
                                              shared_ptr<TreeNode> q) {
        // if root is the common ancestor of p and q, return lowest common
        // ancestror if root is the ancestor of either p or q, return p or q
        // else, return nullptr
        if (root == nullptr)
            return nullptr;
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if ((l == p && r == q) || (l == q && r == p))
            return root;
        if (root == p || root == q)
            return root;
        if (l != nullptr)
            return l;
        if (r != nullptr)
            return r;
        return nullptr;
    }
};

Solution235::Solution235() {}
Solution235::~Solution235() {}

} // namespace LeetCode