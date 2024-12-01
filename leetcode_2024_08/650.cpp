#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        // just to make code faster, remove this line is still ok
        if (n == 1) return 0;

        int steps = 0;
        // minimum prime number
        int i = 2;
        while (i <= n) {
            if (!(n % i)) {
                n /= i;
                // (n%i) == 0 means that copy (n/i) and paste (i-1) times take total (1+(i-1)) == i steps
                steps += i;
                i = 2;
            }
            else i++;
        }
        return steps;
    }
};

int main() {
    Solution S;
    int n = 9;
    cout << S.minSteps(n) << endl;
}