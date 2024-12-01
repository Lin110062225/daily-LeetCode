#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // quick sort -> TLE
    /*
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        //Index of smaller element and Indicate
        //the right position of pivot found so far
        int i = low-1;
        
        for (int j = low; j <= high-1; j++) {
            if (nums[j] < pivot) {
                //Increment index of smaller element
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[high]);
        return (i+1);
    }

    void quickSort(vector<int>& nums, int low, int high) {
        // when low is less than high
        if (low < high) {
            // pi is the partition return index of pivot
            int pi = partition(nums, low, high);
            quickSort(nums, low, pi-1);
            quickSort(nums, pi+1, high);
        }
    }
    */

    // radix sort
    void radixSort(vector<int>& nums) {
        vector <int> radix_nums;
        // find the max value and get its string length
        int mx = -100000;
        for (auto t: nums) {
            // because the range of value is -5*10^4 < value < 5*10^4, we temporarily plus 5*10^4 to all nums.
            t += 50000;
            if (t > mx) mx = t;
            radix_nums.push_back(t);
        }
        int len = to_string(mx).length();
        // radix sort
        int times = 0, mul = 10;
        while (len--) {
            // set 10 boxes
            vector <vector <int>> box (10);
            for (auto t: radix_nums) {
                int id = t % mul;
                for (int i = 0; i < times; i++) id /= 10;  // get the correct number
                box[id].push_back(t);
            }
            radix_nums.clear();
            for (int i = 0; i < 10; i++) {
                for (auto j: box[i]) {
                    radix_nums.push_back(j);
                }
            }
            mul *= 10;
            times++;
        }
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            nums[i] = radix_nums[i] - 50000;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // quickSort(nums, 0, nums.size()-1);
        radixSort(nums);
        return nums;
    }
};

int main() {
    Solution S;
    vector <int> nums = {-74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,64,63,80,28,-30,-58,-11,-44,-87,-22,54,-74,-10,-55,-28,-46,29,10,50,-72,34,26,25,8,51,13,30,35,-8,50,65,-6,16,-2,21,-78,35,-13,14,23,-3,26,-90,86,25,-56,91,-13,92,-25,37,57,-20,-69,98,95,45,47,29,86,-28,73,-44,-46,65,-84,-96,-24,-12,72,-68,93,57,92,52,-45,-2,85,-63,56,55,12,-85,77,-39};
    vector <int> vec = S.sortArray(nums);
    for (auto v: vec) {
        cout << v << ' ';
    } 
}