#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> visited;
    void dfs(int y, int x, int& blocks) {
        if (y >= 0 && x >= 0 && y < visited.size() && x < visited[0].size()) {
            if (visited[y][x]) {
                blocks++;
                visited[y][x] = 0;
                dfs(y-1, x, blocks);
                dfs(y, x-1, blocks);
                dfs(y+1, x, blocks);
                dfs(y, x+1, blocks);
            } 
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int total = 0;

        // count total blocks
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    total++;
                }
            }
        }

        // no island case
        if (total == 0) return 0;

        // just one block case
        if (total == 1) return 1;

        // 0 day case
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    int blocks = 0;
                    visited = grid;
                    dfs(i, j, blocks);
                    if (blocks != total) return 0;
                    break;
                }
            }
        }

        // 1 day case
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    bool done = false;
                    int blocks = 0;
                    visited = grid;
                    if (i > 0) {
                        if (grid[i-1][j]) {
                            dfs(i-1, j, blocks);
                            done = true;
                        }
                    }
                    if (j > 0 && !done) {
                        if (grid[i][j-1]) {
                            dfs(i, j-1, blocks);
                            done = true;
                        }
                    }
                    if (i < r-1 && !done) {
                        if (grid[i+1][j]) {
                            dfs(i+1, j, blocks);
                            done = true;
                        }    
                    }
                    if (j < c-1 && !done) {
                        if (grid[i][j+1]) {
                            dfs(i, j+1, blocks);
                            done = true;
                        }
                    }
                    if (total-1 > blocks) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        // output will only have 0, 1 or 2 days
        return 2;
    }
};

int main() {
    Solution S;
    vector<vector<int>> grid = {{1,1,1,1,0},{1,1,1,1,1},{1,1,1,1,0},{1,1,1,1,1},{1,1,1,0,1},{0,1,0,1,1}};
    cout << S.minDays(grid) << endl;
    /*
    [[1,1,1,1,0,1,0,1]
    ,[1,0,1,0,0,1,0,1]
    ,[1,1,1,1,1,0,1,1]
    ,[0,1,1,1,1,0,1,1]
    ,[0,1,0,1,1,1,1,1]]
    */
}