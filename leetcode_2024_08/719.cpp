#include <bits/stdc++.h>
using namespace std;

// most difficult problem

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // correct solution but TLE -> heap
        /*
        priority_queue<int> pq;
        int len = nums.size();

        for (int i = 0; i < len-1; i++) {
            for (int j = i+1; j < len; j++) {
                pq.push(abs(nums[i] - nums[j]));
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
        */

        // faster solution -> binary search + sliding window
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1] - nums[0];
        
        while (l < r) {
            int mid = (l+r) / 2;
            int count = 0;
            for (int i = l; i < mid-1; i++) {
                int j = i;
                for (j = i+1; j < mid; j++) {
                    if (nums[j] - nums[i] > mid) {
                        break;
                    }
                }
                count += (j - i);
            }
            if (count < k) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }

        return l;
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,6,1};
    int k = 3;
    cout << S.smallestDistancePair(nums, k) << endl;
}