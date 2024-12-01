#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = 0;
        double len = customers.size();
        for (int i = 1; i < len; i++) {
            total += customers.at(i).at(1);
            if (customers.at(i).at(0) < (customers.at(i-1).at(0) + customers.at(i-1).at(1))) {
                total += customers.at(i-1).at(0) + customers.at(i-1).at(1) - customers.at(i).at(0);
                customers.at(i).at(0) = customers.at(i-1).at(0) + customers.at(i-1).at(1);
            }
        }
        total += customers.at(0).at(1); // first
        return total / len;
    }
};

int main() {
    vector <vector<int>> customers;
    Solution S;
    int x, y;
    while (cin >> x >> y) {
        vector <int> v;
        v.push_back(x);
        v.push_back(y);
        customers.push_back(v);
    }
    cout << S.averageWaitingTime(customers) << endl;
}