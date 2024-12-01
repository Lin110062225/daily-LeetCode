#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        // frequency vector
        vector<int> fq(26, 0);
        for (char c: word) fq[c - 'a']++;

        // if number of letters < 9, each char only needs to be pushed once.
        if (26 - count(fq.begin(), fq.end(), 0) < 9) return word.length();
        int sum = 0;
        // non-increasing order
        sort(fq.rbegin(), fq.rend());
        
        for (int i = 0; i < 26; i++) {
            if (!fq[i]) break;
            // if i > 8, 2 pushes will be needed.
            sum += (fq[i] * (i/8 + 1));
        }
        return sum;
    }
};

int main() {
    Solution S;
    string word = "aabbccddeeffgghhiiiiii";
    cout << S.minimumPushes(word) << endl;
}