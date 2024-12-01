#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector <int> mapping_vec;
        // map to vector
        for (auto m: mapping) {
            mapping_vec.push_back(m);
        }
        // pair -> (num after, num original)
        vector <pair <int, int>> pairs;
        for (auto n: nums) {
            int tmp = n, mul = 1, flag = 0;
            if (tmp == 0) flag = 1;  // handle the 0 situation
            int shf = 0;
            while (tmp || flag) {
                shf += mapping_vec[tmp % 10] * mul;
                tmp /= 10;
                mul *= 10;
                flag = 0;
            }
            pairs.push_back({shf, n});
        }
        // sort the transformed nums
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        // to be returned
        for (int i = 0; i < pairs.size(); i++) {
            nums[i] = pairs[i].second;
        }
        return nums;
    }
};

int main() {
    Solution S;
    vector <int> mapping;
    vector <int> nums;
    mapping = {8,9,4,0,2,1,3,5,7,6};
    nums = {991,338,38};
    vector <int> v = S.sortJumbled(mapping, nums);
    for (auto t: v) cout << t << ' ';
}