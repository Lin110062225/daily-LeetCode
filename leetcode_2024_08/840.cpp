#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int subgrids = 0;
        int row = grid.size();
        int col = grid[0].size();
        // start from first 3*3 square
        for (int r = 1; r < row-1; r++) {
            for (int c = 1; c < col-1; c++) {
                // middle number of the 3*3 magic square must be 5
                if (grid[r][c] != 5) continue;

                // grid may contain 0~15
                vector<bool> nums(16, false);
                nums[grid[r-1][c-1]] = true;
                nums[grid[r-1][c]] = true;
                nums[grid[r-1][c+1]] = true;
                nums[grid[r][c-1]] = true;
                nums[grid[r][c]] = true;
                nums[grid[r][c+1]] = true;
                nums[grid[r+1][c-1]] = true;
                nums[grid[r+1][c]] = true;
                nums[grid[r+1][c+1]] = true;

                bool ctn = false;
                for (int i = 0; i < 16; i++) {
                    if (i >= 1 && i <= 9 && !nums[i]) ctn = true;  // magic square must contain 1~9
                    if (i == 0 && i >= 10 && nums[i]) ctn = true;
                }
                if (ctn) continue;

                if (grid[r-1][c-1] + grid[r+1][c+1] != 10) continue;  // top-left to bottom-right
                if (grid[r-1][c+1] + grid[r+1][c-1] != 10) continue;  // top-right to bottom-left
                if (grid[r-1][c] + grid[r+1][c] != 10) continue;  // middle col
                if (grid[r][c-1] + grid[r][c+1] != 10) continue;  // middle row
                if (grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c+1] != 15) continue;  // top row
                if (grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1] != 15) continue;  // bottom row
                if (grid[r-1][c-1] + grid[r][c-1] + grid[r+1][c-1] != 15) continue;  // left col
                if (grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c+1] != 15) continue;  // right col

                subgrids++;
            }
        }
        return subgrids;
    }
};

int main() {
    Solution S;
    vector<vector<int>> grid = {{4,3,8,4}, {9,5,1,9}, {2,7,6,2}};  // {{5,5,5}, {5,5,5}, {5,5,5}}
    cout << S.numMagicSquaresInside(grid) << endl;
}