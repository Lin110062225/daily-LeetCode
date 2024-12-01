#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // find shortest path

        // initialize
        int str_len = source.length();
        int arr_size = original.size();
        long long minCost = 0;
        long long llmax_half = LLONG_MAX / 2;
        vector<vector<long long>> cost_arr(26, vector<long long>(26, llmax_half));
        for (int i = 0; i < arr_size; i++) {
            cost_arr[original[i] - 'a'][changed[i] - 'a'] = min(cost_arr[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }

        // floyd-warshall 
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    // six possible permutations, but four is enough
                    if (cost_arr[i][j] > cost_arr[i][k] + cost_arr[k][j]) {
                        cost_arr[i][j] = cost_arr[i][k] + cost_arr[k][j];
                    }
                    if (cost_arr[i][k] > cost_arr[i][j] + cost_arr[j][k]) {
                        cost_arr[i][k] = cost_arr[i][j] + cost_arr[j][k];
                    }
                    if (cost_arr[j][i] > cost_arr[j][k] + cost_arr[k][i]) {
                        cost_arr[j][i] = cost_arr[j][k] + cost_arr[k][i];
                    }
                    if (cost_arr[j][k] > cost_arr[j][i] + cost_arr[i][k]) {
                        cost_arr[j][k] = cost_arr[j][i] + cost_arr[i][k];
                    }
                    // waste time
                    /*
                    if (cost_arr[k][i] > cost_arr[k][j] + cost_arr[j][i]) {
                        cost_arr[k][i] = cost_arr[k][j] + cost_arr[j][i];
                    }
                    if (cost_arr[k][j] > cost_arr[k][i] + cost_arr[i][j]) {
                        cost_arr[k][j] = cost_arr[k][i] + cost_arr[i][j];
                    }
                    */
                }
            }
        }

        // changing per word
        for (int i = 0; i < str_len; i++) {
            if (source[i] != target[i]) {
                if (cost_arr[source[i] - 'a'][target[i] - 'a'] < llmax_half) {
                    minCost += cost_arr[source[i] - 'a'][target[i] - 'a'];
                }
                else return -1;  // no path
            }
        }
        return minCost;
    }
};

int main() {
    Solution S;
    string source = "abadcdadac"; // "abcd";
    string target = "baddbccdac"; // "acbe";
    vector<char> original = {'d', 'c', 'd', 'c', 'b', 'a'}; // {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'b', 'c', 'a', 'd', 'd'}; // {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {8, 5, 9, 1, 10, 2}; // {2, 5, 5, 1, 2, 20};
    cout << S.minimumCost(source, target, original, changed, cost);
}