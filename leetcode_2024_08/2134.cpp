#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {

        // use sliding window
        int len = nums.size();
        // count the number of 1
        int n1 = count(nums.begin(), nums.end(), 1);

        // cur window size is between l and r but not larger than n1

        // window1 counts the number of 1 in the cur window
        int window1 = 0;
        // max_window1 stores the maximum of window1
        int max_window1 = 0;

        // left = right = 0
        int l = 0;

        // because of the circular array, we ro right to (len + n1)
        // -------------------------------------- //
        //               |---| <- max_window1     //
        // ex: [1, 0, 0, 1] [1, 0, 0, 1]          //
        //      |-----range-----| <- (len + n1)   //
        // -------------------------------------- //

        for (int r = 0; r < len+n1; r++) {
            // (r % len) or r will out of bound
            if (nums[r%len]) {
                window1++;
            }
            // if window1 is too large
            if (r-l+1 > n1) {
                // window1 will minus 1 if nums[l%len] is 1
                window1 -= nums[l%len];
                // move left bound
                l++;
            }
            // update the maximum of window1
            max_window1 = max(max_window1, window1);
        }

        // how many 1 should be moved (not in max_window1)
        return n1 - max_window1;
    }
};

int main() {
    Solution S;
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    cout << S.minSwaps(nums) << endl;
}