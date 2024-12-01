#include <iostream>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int pos = 0, r, count;
        r = n;
        int member[501] = {0};
        while (r > 1) {
            count = k - 1;
            int tmp = pos;
            while (count > 0) {
                if (member[(tmp+1) % n] == 0) {
                    count--;
                }
                tmp++;
            }
            tmp %= n;
            member[tmp] = 1;
            r--;
            for (int j = 1; j < n; j++) {
                if (member[(tmp+j) % n] == 0) {
                    pos = tmp + j;
                    break;
                }
            }
            pos %= n;
        }    
        int result;
        for(int i = 0; i < n; i++){
            if(member[i] != 1){
                result = i + 1;
            }
        }
        return result;
    }
};

int main() {
    int n, k;
    Solution S;
    cin >> n >> k;
    cout << S.findTheWinner(n, k) << endl;
}