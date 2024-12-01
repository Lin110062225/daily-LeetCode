#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int to_delete = 0;
        int b = 0;
        for (char c: s) {
            if (c == 'b') b++;
            // if countB is zero, 
            //     then ans will be 0, because we do not need to remove anything
            // in the case where countB is no longer 0
            //     then we just need to remove the min(countB, ans + 1) 
            //     [this +1 represents the 'a' we encounter in this iteration + ans (those to be removed in previous iteration)]
            else to_delete = min(to_delete + 1, b);
        }
        return to_delete;
    }
};

int main() {
    Solution S;
    string s = "aababbab";
    cout << S.minimumDeletions(s) << endl;
}