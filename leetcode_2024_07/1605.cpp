#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int cur_row = 0, cur_col = 0;
        int rows = rowSum.size(), cols = colSum.size();
        vector <vector<int>> mtx(rows, vector <int> (cols, 0));
        
        while (cur_row < rows || cur_col < cols) {
            if (cur_row >= rows) {
                mtx[cur_row-1][cur_col] = colSum[cur_col];
                cur_col++;
                continue;
            }
            else if (cur_col >= cols) {
                mtx[cur_row][cur_col-1] = rowSum[cur_row];
                cur_row++;
                continue;
            }
            // check which is smaller
            int x = min(rowSum[cur_row], colSum[cur_col]);
            // minus both
            rowSum[cur_row] -= x;
            colSum[cur_col] -= x;
            mtx[cur_row][cur_col] = x;
            // if row/col is zero, go to next row/col
            if (rowSum[cur_row] == 0) {
                cur_row++;
            }
            if (colSum[cur_col] == 0) {
                cur_col++;
            }
        }
        return mtx;
    }
};

int main() {
    Solution S;
    vector <int> rowSum = {5, 7, 10};
    vector <int> colSum = {8, 6, 8};
    vector <vector<int>> sol = S.restoreMatrix(rowSum, colSum);
    for (auto i: sol) {
        for (auto j: i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}