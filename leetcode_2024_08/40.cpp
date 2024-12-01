#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> v;
    set<vector<int>> ans;

    void find_cb(vector<int>& candidates, int target, int k) {
        if (target == 0) {
            ans.insert(v);
            return;
        }

        for (int i = k; i < candidates.size(); i++) {
            // break because candidates[j] (which j>i) is definetly larger than target
            if (target < candidates[i]) break;
            // handle duplicate cases
            if (i > k && candidates[i] == candidates[i-1]) continue;
            v.push_back(candidates[i]);
            find_cb(candidates, target - candidates[i], i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort the vector then we can better handle duplicate cases
        sort(candidates.begin(), candidates.end());
        find_cb(candidates, target, 0);
        // change set to vector
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};

int main() {
    Solution S;
    vector<int> candidates = {4,4,2,1,4,2,2,1,3};
    int target = 6;
    vector<vector<int>> cb = S.combinationSum2(candidates, target);
    for (auto v: cb) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
}