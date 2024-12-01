#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // time limit exceed, no need to erase string.
        /*
        int score = 0, pos = 1;
        if (x > y) {
            while (pos != string::npos) {
                pos = s.find("ab");
                while (pos != string::npos) {
                    score += x;
                    s.erase(pos, 2);
                    pos = s.find("ab");
                }
                pos = s.find("ba");
                if (pos != string::npos) {
                    score += y;
                    s.erase(pos, 2);
                }
                else break;
            }
        }
        else {
            while (pos != string::npos) {
                pos = s.find("ba");
                while (pos != string::npos) {
                    score += y;
                    s.erase(pos, 2);
                    pos = s.find("ba");
                }
                pos = s.find("ab");
                if (pos != string::npos) {
                    score += x;
                    s.erase(pos, 2);
                }
                else break;
            }
        }
        return score;
        */

        int score = 0;
        int hs, ls;   // high | low score
        char hc, lc;  // high | low char
        stack <char> stk, stk_2;  // search two times
        if (x > y) {
            hs = x;
            ls = y;
            hc = 'a';
            lc = 'b';
        }
        else {
            hs = y;
            ls = x;
            hc = 'b';
            lc = 'a';
        }
        for (auto c: s) {
            if (stk.empty()) {  // avoid crash
                stk.push(c);
                continue;
            }
            if (c == lc && stk.top() == hc) {
                stk.pop();
                score += hs;
            }
            else stk.push(c);
        }
        while (!stk.empty()) {
            if (stk_2.empty()) {  // avoid crash
                stk_2.push(stk.top());
                stk.pop();
                continue;
            }
            if (stk.top() == lc && stk_2.top() == hc) {
                stk_2.pop();
                score += ls;
            }
            else stk_2.push(stk.top());
            stk.pop();
        }
        return score;
    }
};

int main() {
    string s;
    int x, y;
    Solution S;
    cin >> s >> x >> y;
    cout << S.maximumGain(s, x, y) << endl;
}