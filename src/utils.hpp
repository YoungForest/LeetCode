#pragma once
#include <algorithm>
#include <memory>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

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
    if (root == nullptr)
        return ret;
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
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
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

string boolToString(bool input) { return input ? "True" : "False"; }

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
