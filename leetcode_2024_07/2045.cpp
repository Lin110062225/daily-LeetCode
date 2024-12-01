#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // find the second shortest path (steps)
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // creat neighbor map
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        // {node, current step}
        queue<pair<int, int>> q;
        q.push({1, 0});

        // to find minimum and second minimum steps
        vector<int> dist(n+1, INT_MAX), dist_2(n+1, INT_MAX);
        dist[1] = 0;

        // dijkstra
        while (!q.empty()) {
            int cur_node = q.front().first;
            int cur_step = q.front().second + 1;
            q.pop();

            for (auto v: mp[cur_node]) {
                // record minimum dist
                if (dist[v] > cur_step) {
                    dist_2[v] = dist[v];
                    dist[v] = cur_step;
                    q.push({v, cur_step});
                }
                // record second minimum dist
                else if (dist[v] < cur_step && dist_2[v] > cur_step) {
                    dist_2[v] = cur_step;
                    q.push({v, cur_step});
                }
            }
        }
        
        // no path
        if (dist_2[n] == INT_MAX) return -1;

        // calculate the time of the second shortest path
        int steps = dist_2[n];
        int total_time = 0;

        while (steps--) {
            int mul = total_time / change;
            if (mul % 2) {  // red light situation
                total_time = change * (mul + 1);
            }
            total_time += time;
        }
        return total_time;
    }
};

int main() {
    Solution S;
    int n = 5, time = 3, change = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
    cout << S.secondMinimum(n, edges, time, change) << endl;
}