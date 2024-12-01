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
    vector <int> dfs(TreeNode* node, int &count, int dis) {
        // if it is leaf node, push back distance = 1.
        if (node->left == nullptr && node->right == nullptr) {
            vector <int> tmp_node;
            tmp_node.push_back(1);
            return tmp_node;
        }
        // dfs
        vector <int> left_dis, right_dis;
        if (node->left) left_dis = dfs(node->left, count, dis);
        if (node->right) right_dis = dfs(node->right, count, dis);
        // check each pair of nodes whether their distance is less than the limited distance.
        for (auto l: left_dis) {
            for (auto r: right_dis) {
                if (l + r <= dis) {
                    count++;
                }
            }
        }
        // the vector to be returned
        vector <int> total_dis(left_dis.size() + right_dis.size());
        merge(left_dis.begin(), left_dis.end(), right_dis.begin(), right_dis.end(), total_dis.begin());
        // plus 1 distance for each node
        for (int i = 0; i < total_dis.size(); i++) {
            total_dis[i] += 1;
        }
        return total_dis;
    }
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, count, distance);
        return count;
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
    
    cout << S.countPairs(root, 3) << endl;
}