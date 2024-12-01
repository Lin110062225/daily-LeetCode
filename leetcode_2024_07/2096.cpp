#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* node, string &path, int target, string &ans) {
        if (node->val == target) {
            ans = path;  // store the answer path
            return;
        }
        if (node->left != nullptr) {
            path.push_back('L');
            dfs(node->left, path, target, ans);
            path.pop_back();
        }
        if (!ans.empty()) return;  // minimize time complexity
        if (node->right != nullptr) {
            path.push_back('R');
            dfs(node->right, path, target, ans);
            path.pop_back();
        }
    }
    // use dfs
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start_path, dest_path, tmp_path;
        dfs(root, tmp_path, startValue, start_path);
        dfs(root, tmp_path, destValue, dest_path);
        int min_len = min(start_path.length(), dest_path.length()), same = 0;
        for (int i = 0; i < min_len; i++) {
            if (start_path[i] == dest_path[i]) same++;  // delete the overlapped part of two paths
            else break;  // don't forget to break
        }
        return string(start_path.length()-same, 'U') + dest_path.substr(same);  // change the L/R in start_path to U
    }
};

int main() {
    Solution S;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    cout << S.getDirections(root, 3, 6);
}