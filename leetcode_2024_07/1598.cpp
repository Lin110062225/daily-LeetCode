#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        for (auto t: logs) {
            if (t[1] == '.' && steps) steps--;
            else if (t[0] != '.') steps++;
        }
        return steps;
    }
};

int main() {
    vector <string> logs;
    string tmp;
    Solution S;
    while (cin >> tmp) {
        logs.push_back(tmp);
    }
    cout << S.minOperations(logs) << endl;
}