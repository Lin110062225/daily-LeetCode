#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // my code
        /*
        vector <int> lucky;
        vector <vector<int>> matrix_T(matrix[0].size(), vector <int> (matrix.size()));
        vector <int> c;
        set <int> s;
        for (int i = 0; i < matrix.size(); i++) {
            int min = 99999;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
                matrix_T[j][i] = matrix[i][j];
            }
            c.push_back(min);
            s.insert(min);
        }
        for (int i = 0; i < matrix_T.size(); i++) {
            int max = 0;
            for (int j = 0; j < matrix_T[i].size(); j++) {
                if (matrix_T[i][j] > max) {
                    max = matrix_T[i][j];
                }
            }
            c.push_back(max);
            s.insert(max);
        }
        for (auto t: s) {
            if (count(c.begin(), c.end(), t) > 1) {
                lucky.push_back(t);
            }
        }
        return lucky;
        */
        // golden code
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> row_minimums(rows, INT_MAX);
        vector<int> col_maximums(cols, 0);
        
        for (int row_ind = 0; row_ind < rows; ++row_ind) {
            for (int col_ind = 0; col_ind < cols; ++col_ind) {
                int el = matrix[row_ind][col_ind];
                row_minimums[row_ind] = min(row_minimums[row_ind], el);
                col_maximums[col_ind] = max(col_maximums[col_ind], el);
            }
        }
        for (int row_ind = 0; row_ind < rows; ++row_ind) {
            for (int col_ind = 0; col_ind < cols; ++col_ind) {
                int el = matrix[row_ind][col_ind];
                if (el == row_minimums[row_ind] && el == col_maximums[col_ind]) {
                    return {el};
                }
            }
        }
        return {};
    }
};

int main() {
    vector <vector<int>> m;
    vector <int> sub;
    sub.push_back(7);
    sub.push_back(8);
    m.push_back(sub);
    sub.clear();
    sub.push_back(1);
    sub.push_back(2);
    m.push_back(sub);
    Solution S;
    vector <int> lucky = S.luckyNumbers(m);
    for (auto v: lucky) cout << v << endl;
}