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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root;
        map <int, TreeNode*> node_map;
        map <int, bool> parent_map;
        for (auto t: descriptions) {
            int val = t.at(0);
            if (node_map.find(val) == node_map.end()) {
                node_map[val] = new TreeNode(val);
                parent_map[val] = false;
            }
            int child = t.at(1);
            if (node_map.find(child) == node_map.end()) {
                node_map[child] = new TreeNode(child);
                parent_map[child] = true;
            }
            else {
                parent_map[child] = true;
            }
            bool left = t.at(2);
            if (left) {
                node_map[val]->left = node_map[child];
            }
            else {
                node_map[val]->right = node_map[child];
            }
        }
        // find the node who doesn't have parent
        for (auto node: parent_map) {
            if (!node.second) {
                root = node_map[node.first];
                break;
            }
        }
        return root;
    }
};

int main() {
    vector <vector<int>> descriptions;
    int parent, child, isleft;
    Solution S;
    while (cin >> parent >> child >> isleft) {
        vector <int> node;
        node.push_back(parent);
        node.push_back(child);
        node.push_back(isleft);
        descriptions.push_back(node);
    }
    queue <TreeNode*> q;
    q.push(S.createBinaryTree(descriptions));
    while (!q.empty()) {
        TreeNode *lt, *rt;
        lt = q.front()->left;
        rt = q.front()->right;
        if (lt != nullptr) {
            q.push(lt);
        }
        if (rt != nullptr) {
            q.push(rt);
        }
        cout << q.front()->val << ' ';
        q.pop();
    }
}