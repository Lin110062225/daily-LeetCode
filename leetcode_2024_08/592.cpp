#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reduce(int& num, int& dom) {
        int d = __gcd(num, dom);
        num /= d;
        dom /= d;
    }
    string fractionAddition(string expression) {
        int num = 0;
        int dom = 0;
        int i = 0;
        int len = expression.length();
        while (i < len) {
            char c = expression[i];
            if (c == '-' || c == '+' || i == 0) {
                string num2 = "";
                string dom2 = "";
                bool up = true;
                if (i == 0) {
                    i--;
                    c = '+';
                }
                int j = i+1;
                while (expression[j] != '+' || expression[j] != '-') {
                    if (expression[j] == '/') {
                        up = false;
                    }
                    else {
                        if (up) {
                            num2 = num2 + expression[j];
                        }
                        else {
                            dom2 = dom2 + expression[j];
                        }
                    }
                    j++;
                    if (j > len-1) break;
                }
                if (c == '-') {
                    if (num == 0 || dom == 0) {
                        num = -stoi(num2);
                        dom = stoi(dom2);
                    }
                    else {
                        int new_num = num * stoi(dom2);
                        int new_num2 = stoi(num2) * dom;
                        int new_dom = dom * stoi(dom2);
                        num = new_num - new_num2;
                        dom = new_dom;
                        reduce(num, dom);
                    }
                }
                else {
                    if (num == 0 || dom == 0) {
                        num = stoi(num2);
                        dom = stoi(dom2);
                    }
                    else {
                        int new_num = num * stoi(dom2);
                        int new_num2 = stoi(num2) * dom;
                        int new_dom = dom * stoi(dom2);
                        num = new_num + new_num2;
                        dom = new_dom;
                        reduce(num, dom);
                    }
                }
                i = j;
            }
            else i++;
        }
        return to_string(num) + "/" + to_string(dom);
    }
};

int main() {
    Solution S;
    string expression = "-1/2+1/2+1/3";
    cout << S.fractionAddition(expression) << endl;
}