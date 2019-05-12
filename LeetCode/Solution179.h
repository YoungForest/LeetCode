#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::string;
using std::vector;
using std::accumulate;
using std::sort;
using std::to_string;
using std::min;

class Solution179
{
public:
	Solution179();
	~Solution179();
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](const auto& lhs, const auto& rhs) -> bool {
			auto l = to_string(lhs), r = to_string(rhs);
			return stol(l + r) > stol(r + l);
		});
		if (nums.front() == 0)
			return "0";
		return accumulate(nums.cbegin(), nums.cend(), string(""), [](auto lhs, auto rhs) -> auto {
			lhs += to_string(rhs);
			return lhs;
		});
	}
};

