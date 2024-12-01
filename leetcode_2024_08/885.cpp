#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows * cols;
        int cur_row = rStart, cur_col = cStart;
        vector<vector<int>> ans;

        int lines = 0;  // how many lines on the grid
        int steps = 0;
        int last_turn = 0;  // last turn position

        int dir = 0;
        int row_dir[4] = { 0, 1, 0, -1};
        int col_dir[4] = { 1, 0, -1, 0};
        
        while (1) {
            // if current position is in the grid
            if (cur_row < rows && cur_col < cols && cur_row >= 0 && cur_col >= 0) {
                ans.push_back({cur_row, cur_col});
                n--;
            }

            // break when grid is finished
            if (!n) break;

            cur_row += row_dir[dir];
            cur_col += col_dir[dir];

            steps++;

            // turn pos: 0, 1, 2, 4, 6, 9, 12, 16, ...
            //            +1 +1 +2 +2 +3 +3  +4 ...
            if (steps == last_turn + lines/2 + 1) {  // if steps == turning pos
                lines++;
                dir = lines % 4;
                last_turn = steps;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution S;
    int rows = 5, cols = 6, rStart = 1, cStart = 4;
    vector<vector<int>> smIII = S.spiralMatrixIII(rows, cols, rStart, cStart);
    for (auto v: smIII) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
}