#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();

        // use dynamic programming
        vector<long long> dp(col, 0);

        for (int i = 0; i < row; i++) {
            // suppose no column change first
            for (int j = 0; j < col; j++) {
                dp[j] += points[i][j];
            }
            // check whether (left number - 1) is larger
            for (int j = 1; j < col; j++) {
                dp[j] = max(dp[j], dp[j-1]-1);
            }
            // check whether (right number - 1) is larger
            for (int j = col-2; j >= 0; j--) {
                dp[j] = max(dp[j], dp[j+1]-1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution S;
    vector<vector<int>> points = {{1,2,3},{1,5,1},{3,1,1}};
    cout << S.maxPoints(points) << endl;
}