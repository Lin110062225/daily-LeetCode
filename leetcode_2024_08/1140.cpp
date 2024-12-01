#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int play_b(vector<int>& piles, int a, int b, int M, int cur) {
        if (cur > piles.size()-1) {
            // cout << "a:" << a << endl;
            return a;
        }
        int stones = b;
        int mn = 20000;
        int mx = -1;
        for (int i = 0; i < 2*M; i++) {
            if (i+cur > piles.size()-1) break;
            stones += piles[i+cur];
            int tmp = play_a(piles, a, stones, max(i+1, M), cur+i+1);
            mn = min(tmp, mn);
            mx = max(tmp, mx);
            if (tmp == stones) return mx;
        }
        return mn;
    }
    int play_a(vector<int>& piles, int a, int b, int M, int cur) {
        if (cur > piles.size()-1) {
            // cout << "b:" << b << endl;
            return b;
        }
        int stones = a;
        int mn = 20000;
        int mx = -1;
        for (int i = 0; i < 2*M; i++) {
            if (i+cur > piles.size()-1) break;
            stones += piles[i+cur];
            int tmp = play_b(piles, stones, b, max(i+1, M), cur+i+1);
            mn = min(tmp, mn);
            mx = max(tmp, mx);
            if (tmp == stones) return mx;
        }
        return mn;
    }
    int stoneGameII(vector<int>& piles) {
        return play_a(piles, 0, 0, 1, 0);
    }
};

int main() {
    Solution S;
    vector<int> piles = {2,7,9,4,4}; // 1,2,3,4,5,100
    cout << S.stoneGameII(piles) << endl;
}