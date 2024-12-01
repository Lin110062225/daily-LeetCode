#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int num = books.size();

        // dp[i] stores the minimium total height of 0~i books
        vector<int> dp(num + 1, INT_MAX);

        // no book, height = 0
        dp[0] = 0;

        // 1 to n books
        for (int i = 1; i <= num; i++) {
            int h = books[i-1][1], w = books[i-1][0];

            // suppose the ith book is going to the next shelf
            dp[i] = dp[i-1] + h;

            // j start from ith book
            for (int j = i-1; j > 0; j--) {

                // check if (cur book width + last book width) > shelf width
                w += books[j-1][0];

                // break if cur book is going to the next shelf
                // meanwhile dp[i] has already stored the total height of i books
                if (w > shelfWidth) break;

                // if cur book stays at cur shelf, h stores the max(cur book height, last book height)
                h = max(h, books[j-1][1]);
                
                // dp[i] stores the min(previous total height + updated height of cur shelf, height that cur book goes to the next shelf)
                dp[i] = min(dp[j-1] + h, dp[i]);
            }
        }
        return dp[num];
    }
};

int main() {
    Solution S;
    vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
    int shelfWidth = 4;
    cout << S.minHeightShelves(books, shelfWidth) << endl;
}