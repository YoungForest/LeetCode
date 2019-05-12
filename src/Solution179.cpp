#pragma once
#include "utils.hpp"

namespace LeetCode {

class Solution179 {
  public:
    Solution179();
    ~Solution179();
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(),
             [](const auto &lhs, const auto &rhs) -> bool {
                 auto l = to_string(lhs), r = to_string(rhs);
                 return stol(l + r) > stol(r + l);
             });
        if (nums.front() == 0)
            return "0";
        return accumulate(
            nums.cbegin(), nums.cend(), string(""),
            [](auto lhs, auto rhs) -> auto {
                lhs += to_string(rhs);
                return lhs;
            });
    }
};

Solution179::Solution179() {}

Solution179::~Solution179() {}

} // namespace LeetCode
