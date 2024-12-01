#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ten_digit[10] = {  // 20, 30, ..., 90
        "",
        "",
        " Twenty",
        " Thirty",
        " Forty",
        " Fifty",
        " Sixty",
        " Seventy",
        " Eighty",
        " Ninety"
    };
    string digit[10] = {
        "",
        " One",
        " Two",
        " Three",
        " Four",
        " Five",
        " Six",
        " Seven",
        " Eight",
        " Nine"
    };
    string ten_up[10] = {  // 11 ~ 19
        " Ten",
        " Eleven",
        " Twelve",
        " Thirteen",
        " Fourteen",
        " Fifteen",
        " Sixteen",
        " Seventeen",
        " Eighteen",
        " Nineteen"
    };
    string period[4] = {  // when we meet a period
        "",
        " Thousand",
        " Million",
        " Billion"
    };
    
    string numberToWords(int num) {
        string words = "";
        // int to string
        string num_str = to_string(num);

        /*
        1,000              thousand
        1,000,000          million
        1,000,000,000      billion
        --21,4748,3647--   INT_MAX
        1,000,000,000,000  trillion

        It means that input is less than one trillion
        */
        
        int len = num_str.length();

        // bmt checks current position is in billion, million or thousand
        int bmt = (len - 1) / 3;

        // if check > 0, we will only need to concat period[bmt] to words
        // for example: "2024"
        // when we come to the second '2', check++, words = "20" + '2' + '4'
        // hence we will only need to plus "" to words after i++ instead of plusing '4' again
        int check = 0;

        // start from the most significant digit
        for (int i = 0; i < len; i++) {
            // check every three digits (billion, million, thousand)
            // position(d) in 000 is [2], [1], [0]
            // 
            // for example: "2001"
            // c = '2', d = 0
            // c = '0', d = 2
            // c = '0', d = 1
            // c = '1', d = 0
            //
            int d = (len - i - 1) % 3;
            if (d == 2) {
                // no zero hundred
                if (num_str[i] != '0') {
                    words =  words + digit[num_str[i]-'0'] + " Hundred";
                    check++;
                }
            }
            else if (d == 1) {
                // numbers in 11 ~ 19 are special
                if (num_str[i] == '1') {
                    words = words + ten_up[num_str[i+1]-'0'];
                }
                else {
                    // plus two digits
                    words = words + ten_digit[num_str[i]-'0'] + digit[num_str[i+1]-'0'];
                }
                // check++ if digit in (i+1) is plused already
                if (num_str[i] != '0' || num_str[i+1] != '0') check++;
            }
            else {
                if (check) {
                    // only need to plus "billion", "million", "thousand" or ""
                    words = words + period[bmt];
                }
                else if (num_str[i] != '0') {
                    // start with d == 0
                    // for example: "2486", when i == 0, words = '2' + "thousand"
                    words = words + digit[num_str[i]-'0'] + period[bmt];
                }
                // for example: "million" -> "thousand" (period[2] -> period[1])
                bmt--;
                check = 0;
            }
        }
        // delete the extra space
        if (words[0] == ' ') words = words.substr(1, words.size()-1);
        // when num == 0, we should return "Zero"
        if (words == "") words = "Zero";
        return words;
    }
};

int main() {
    Solution S;
    cout << S.numberToWords(100009000) << endl;
}