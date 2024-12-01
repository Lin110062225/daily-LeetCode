#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
        vector<int> dp(n, 0);

        // where to get dp
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        // first ugly number is 1 (2^0 * 3^0 * 5^0)
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            
            int mul2 = 2*dp[i2];
            int mul3 = 3*dp[i3];
            int mul5 = 5*dp[i5];

            // smallest number is next ugly number
            int mn = min(min(mul2, mul3), mul5);

            if (mn == mul2) i2++;
            if (mn == mul3) i3++;
            if (mn == mul5) i5++;

            dp[i] = mn;
        }

        return dp[n-1];
    }
};

int main() {
    Solution S;
    int n = 10;
    cout << S.nthUglyNumber(10) << endl;
}