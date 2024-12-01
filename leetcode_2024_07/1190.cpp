#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int len = s.length();
        stack <int> pos;
        string ans;

        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                pos.push(i);  // position of '('
            }
            else if (s[i] == ')') {
                reverse(s.begin() + pos.top() + 1, s.begin() + i);  // reverse(pos('(')+1, pos(')')-1)
                pos.pop();
            }
        }
        for (int i = 0; i < len; i++) {
            if (s[i] != '(' && s[i] != ')') {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main() {
    string s;
    Solution S;
    cin >> s;
    cout << S.reverseParentheses(s) << endl;
}