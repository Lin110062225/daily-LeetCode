#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // dijkstra -> TLE
        /*
        // handle all edges
        vector<vector<int>> e(n, vector<int>(n, -1));
        int edges_size = edges.size();
        for (int i = 0; i < edges_size; i++) {
            e[edges[i][0]][edges[i][1]] = e[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int i = 0; i < n; i++) e[i][i] = 0;

        // to record the numbers of neighbors
        vector<int> neighbor(n, 0);

        // count all cities 
        for (int start = 0; start < n; start++) {
            vector<int> path(n, -1);
            path[start] = 0;
            queue<int> q;
            q.push(start);

            // dijkstra
            while (!q.empty()) {
                for (int i = 0; i < n; i++) {
                    if (e[q.front()][i] > 0 && path[q.front()] + e[q.front()][i] <= distanceThreshold && i != q.front() && i != start) {
                        q.push(i);
                        // if never visit, neighbor[start]++
                        if (path[i] == -1) neighbor[start]++;
                        // update shortest path
                        if (path[i] < path[q.front()] + e[q.front()][i]) {
                            path[i] = path[q.front()] + e[q.front()][i];
                            // make algorithm faster
                            e[start][i] = e[i][start] = path[i];
                        }
                    }
                }
                q.pop();
            }
        }
        
        // find the city with the least neighbors
        int mn = n + 1, x = 0;
        for (int i = 0; i < n; i++) {
            if (neighbor[i] <= mn) {
                if (neighbor[i] == mn) x = max(i, x);
                else {
                    x = i;
                    mn = neighbor[i];
                }
            }
        }
        return x;
        */

        // floyd-warshall

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (auto e: edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = dist[v][u] = w;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int minCity = 0, mn = n + 1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold && i != j) {
                    count++;
                }
            }
            if (count <= mn) {
                mn = count;
                minCity = i;
            }
        }
        return minCity;
    }
};

int main() {
    Solution S;
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int dT = 4;
    cout << S.findTheCity(n, edges, dT);
}