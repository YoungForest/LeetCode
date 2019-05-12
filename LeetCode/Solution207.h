#pragma once
#include "pch.h"

class Solution207
{
public:
	Solution207();
	~Solution207();
	unordered_set<int> global_seen;
	bool dfs(int node, vector<vector<int>>& begins, unordered_set<int>& seen) {
		global_seen.insert(node);
		if (seen.find(node) != seen.end())
			return false; // 发现环
		seen.insert(node);
		for (auto another_edge : begins.at(node)) {
			if (!dfs(another_edge, begins, seen))
				return false;
		}
		seen.erase(node);
		return true;
	}
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// dfs 判断有向图是否有环
		vector<vector<int>> begins(numCourses);
		vector<vector<int>> ends(numCourses);

		for (const auto & edge : prerequisites) {
			begins[edge[0]].push_back(edge[1]);
			ends[edge[1]].push_back(edge[0]);
		}
		int count = 0;
		for (int i = 0; i < numCourses; ++i) {
			if (ends[i].size() == 0) {
				// dfs
				unordered_set<int> seen;
				if (!dfs(i, begins, seen))
					return false;
				++count;
			}
		}
		return count > 0 && global_seen.size() == numCourses;
	}
};
