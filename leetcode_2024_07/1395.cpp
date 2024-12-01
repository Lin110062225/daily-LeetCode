#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int cnt = 0;

        // i is the middle integer
        for (int i = 1; i < n-1; i++) {
            // [0]: descend, [1]: ascend
            int l[2] = {0}, r[2] = {0};

            // left part
            for (int j = 0; j < i; j++) {
                // all the integers in rating is unique -> no equal(==) situation
                l[rating[i] > rating[j]]++;  // if ascend, l[1]++, else l[0]++
            }

            // right part
            for (int k = i+1; k < n; k++) {
                r[rating[i] < rating[k]]++;  // if ascend, r[1]++, else r[0]++
            }

            // (left int larger than mid) * (right int less than mid) = descend cases
            // (left int less than mid) * (right int larger than mid) = ascend cases
            cnt += l[0] * r[0] + l[1] * r[1];
        }
        return cnt;
    }
};

int main() {
    Solution S;
    vector<int> rating = {2, 5, 3, 4, 1};
    cout << S.numTeams(rating) << endl;
}