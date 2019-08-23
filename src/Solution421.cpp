#pragma once

#include "utils.hpp"
namespace LeetCode {

class Solution421 {
  public:
    Solution421();
    ~Solution421();

  private:
    // left 1, right 0
    struct Node {
        shared_ptr<Node> left = nullptr, right = nullptr;
    };
  public:
    int findMaximumXOR(vector<int> &nums) {
        // build tire
        auto root = make_shared<Node>();
        for (int n : nums) {
            auto current = root;
            for (int i = 31; i >= 0; --i) {
                int v = (n >> i) & 1;
                if (v == 1) {
                    if (current->left == nullptr) {
                        current->left = make_shared<Node>();
                    }
                    current = current->left;
                } else {
                    if (current->right == nullptr) {
                        current->right = make_shared<Node>();
                    }
                    current = current->right;
                }
            }
        }
        // find answer
        int ans = 0;
        for (int n : nums) {
            // the max xor with n
            auto current = root;
            int local_ans = 0;
            for (int i = 31; i >= 0; --i) {
                int v = (n >> i) & 1;
                if (current->left && current->right) {
                    current = v == 1 ? current->right : current->left;
                    local_ans += 1 << i;
                } else {
                    if (v == 1 && current->right)
                        local_ans += 1 << i;
                    if (v == 0 && current->left)
                        local_ans += 1 << i;
                    current = current->left != nullptr ? current->left : current->right;
                }
            }
            ans = max(ans, local_ans);
        }
        return ans;
    }
};

Solution421::Solution421() {}
Solution421::~Solution421() {}

} // namespace LeetCode