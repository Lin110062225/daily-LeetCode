#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        // minimum and maximum
        int a = 20000;
        int b = -20000;

        // second minimum and second maximum
        int a2 = a;
        int b2 = b;

        // position
        int a_pos = -1;
        int b_pos = -1;

        for (int i = 0; i < n; i++) {

            if (a > arrays[i][0]) {
                a2 = a;
                a = arrays[i][0];
                a_pos = i;
            }
            else if (a2 > arrays[i][0]) {
                a2 = arrays[i][0];
            }

            if (b <= arrays[i].back()) {
                b2 = b;
                b = arrays[i].back();
                b_pos = i;
            }
            else if (b2 <= arrays[i].back()){
                b2 = arrays[i].back();
            }
        }

        // cannot take from same vector
        if (b_pos != a_pos) return b-a;

        return max(b2 - a, b - a2);
    }
};

int main() {
    Solution S;
    vector<vector<int>> arrays = {{1,2,3},{4,5},{1,2,3}};
    cout << S.maxDistance(arrays) << endl;
}