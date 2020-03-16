#pragma once

#include "utils.hpp"
namespace LeetCode {

class Solution1238 {
  public:
    Solution1238();
    ~Solution1238();
    bool isAdjacent(int a, int b) {
        int c = a ^ b;
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += (c >> i) & 1;
        }
        return count == 1;
    }

  private:
    bool dfs(unordered_map<int, vector<int>> &edges, vector<int> &current,
             unordered_set<int> &seen, const size_t n) {
        if (current.size() >= n) {
            if (isAdjacent(current.front(), current.back())) {
                return true;
            } else {
                return false;
            }
        }
        for (auto i : edges[current.back()]) {
            if (seen.find(i) == seen.end()) {
                current.push_back(i);
                seen.insert(i);
                if (dfs(edges, current, seen, n)) {
                    return true;
                }
                current.pop_back();
                seen.erase(i);
            }
        }
        return false;
    }

  public:
    vector<int> circularPermutation(int n, int start) {
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = i + 1; j < (1 << n); ++j) {
                if (isAdjacent(i, j)) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        vector<int> current;
        current.push_back(start);
        unordered_set<int> seen;
        seen.insert(start);
        if (dfs(edges, current, seen, (1 << n))) {
            return current;
        } else {
            return {};
        }
    }
};

Solution1238::Solution1238() {}
Solution1238::~Solution1238() {}

} // namespace LeetCode