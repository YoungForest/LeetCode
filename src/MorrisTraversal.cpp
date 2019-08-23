#include "utils.hpp"

vector<int> MorrisTraversal(shared_ptr<TreeNode> root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    shared_ptr<TreeNode> current, pre;
    current = root;

    while (current) {
        if (current->left == nullptr) {
            ret.push_back(current->val);
            current = current->right;
        } else {
            auto pre = current->left;
            while (pre->right != nullptr && pre->right != current) {
                pre = pre->right;
            }
            if (pre->right == nullptr) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = nullptr;
                ret.push_back(current->val);
                current = current->right;
            }
        }
    }
    return ret;
}