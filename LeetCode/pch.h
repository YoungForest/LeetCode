// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here
#include <vector>
#include <unordered_set>
#include <string>
#include <tuple>
#include <queue>
#include <stack>
#include <sstream>
#include <memory>

using namespace std;

struct TreeNode;

struct TreeNode {
	int val;
	shared_ptr<TreeNode> left;
	shared_ptr<TreeNode> right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversal(shared_ptr<TreeNode> root);

void trimLeftTrailingSpaces(string &input);

void trimRightTrailingSpaces(string &input);

vector<int> stringToIntegerVector(string input);
shared_ptr<TreeNode> stringToTreeNode(string input);

string boolToString(bool input);

vector<int> inorderTraversal(shared_ptr<TreeNode> root) {
	vector<int> ret;
	if (root == nullptr) return ret;
	stack<shared_ptr<TreeNode>> s;
	while (root != nullptr || !s.empty()) {
		while (root != nullptr) {
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		ret.push_back(root->val);
		root = root->right;
	}
	return ret;
}

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

shared_ptr<TreeNode> stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	auto root = make_shared<TreeNode>(stoi(item));
	queue<shared_ptr<TreeNode>> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		auto node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = make_shared<TreeNode>(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = make_shared<TreeNode>(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

#endif //PCH_H
