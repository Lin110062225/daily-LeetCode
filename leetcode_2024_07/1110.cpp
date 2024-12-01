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
    TreeNode* dfs(TreeNode* node, set <int> &del, vector <TreeNode*> &nodes) {
        if (node->left) node->left = dfs(node->left, del, nodes);
        if (node->right) node->right = dfs(node->right, del, nodes);

        if (del.find(node->val) != del.end()) {
            if (node->left) nodes.push_back(node->left);
            if (node->right) nodes.push_back(node->right);
            return nullptr;
        }
        return node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector <TreeNode*> nodes;
        // do not actually delete the node, make the left/right point to null.
        // bfs also work, but I use dfs here.
        set <int> del;
        for (auto v: to_delete) del.insert(v);

        if (root->left) root->left = dfs(root->left, del, nodes);
        if (root->right) root->right = dfs(root->right, del, nodes);

        if (del.find(root->val) != del.end()) {
            if (root->left) nodes.push_back(root->left);
            if (root->right) nodes.push_back(root->right);
        }
        else nodes.push_back(root);
        
        return nodes;
    }
};

int main() {
    Solution S;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector <int> to_delete;
    to_delete.push_back(3);
    to_delete.push_back(5);

    vector <TreeNode*> delNodes;
    delNodes = S.delNodes(root, to_delete);

    for (auto v: delNodes) {
        cout << v->val << endl;
    }
}