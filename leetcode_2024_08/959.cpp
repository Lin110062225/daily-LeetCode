#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int y, int x, vector<vector<bool>>& pixels) {
        if (y >= 0 && x >= 0 && y < pixels.size() && x < pixels.size() && !pixels[y][x]) {
            pixels[y][x] = true;
            dfs(y, x-1, pixels);
            dfs(y-1, x, pixels);
            dfs(y, x+1, pixels);
            dfs(y+1, x, pixels);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();

        // cut every grid[x][y] to 3*3 blocks
        vector<vector<bool>> pixels(n*3, vector<bool>(n*3, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '\\') {
                    pixels[i*3][j*3] = true;
                    pixels[i*3+1][j*3+1] = true;
                    pixels[i*3+2][j*3+2] = true;
                    /*
                    [ T F F ]
                    [ F T F ] -> '\'
                    [ F F T ]
                    */
                }
                else if (grid[i][j] == '/') {
                    pixels[i*3][j*3+2] = true;
                    pixels[i*3+1][j*3+1] = true;
                    pixels[i*3+2][j*3] = true;
                    /*
                    [ F F T ]
                    [ F T F ] -> '/'
                    [ T F F ]
                    */
                }
            }
        }

        int np = pixels.size();  // np = n*3
        int blocks = 0;

        for (int i = 0; i < np; i++) {
            for (int j = 0; j < np; j++) {
                if (!pixels[i][j]) {
                    dfs(i, j, pixels);  // fill the blocks with 'true'
                    blocks++;
                }
            }
        }
        return blocks;
    }
};

int main() {
    Solution S;
    vector<string> grid = {{"/\\"}, {"\\/"}};
    cout << S.regionsBySlashes(grid) << endl;
}