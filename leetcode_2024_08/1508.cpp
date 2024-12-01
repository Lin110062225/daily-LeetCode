#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapify(int arr[], int n, int i) {
        // Initialize smallest as root
        int mn = i;
        // left/right child
        int l = i * 2;
        int r = i * 2 + 1;
    
        // If left child is less than root
        if (l < n && arr[l] < arr[mn]) mn = l;
    
        // If right child is less than smallest so far
        if (r < n && arr[r] < arr[mn]) mn = r;
    
        // If smallest is not root
        if (mn != i) {
            swap(arr[i], arr[mn]);
            // Recursively heapify the affected sub-tree
            heapify(arr, n, mn);
        }
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // heap
        int arr[510000] = {0};  // (1001 * 1002 / 2) < 510000
        int size = 0;

        for (int i = 1; i <= n; i++) {
            // subarray sum
            int sum = 0;
            for (int j = i; j <= n; j++) {
                sum += nums[j-1];
                size++;
                // min heapify
                int k = size;
                arr[size] = sum;  // insert new node to rightmost leaf
                while (arr[k] < arr[k/2]) {  // swap position recursively if parent is larger than children
                    swap(arr[k], arr[k/2]);
                    k /= 2;
                }
            }
        }

        // sum from left to right
        int sum_lr = 0;
        // we will know the answer when i == right, doesn't need to go to i == size
        for (int i = 1; i <= right; i++) {
            if (left <= i && i <= right) {
                // root of heap (arr[1]) == smallest number
                sum_lr += arr[1];
                sum_lr %= (int(pow(10, 9)) + 7);  // mod 10e9 + 7
            }
            // make the rightmost leaf to arr[1] (root)
            arr[1] = arr[size--];
            // then keep heapifying until we get the new root
            heapify(arr, size, 1);
        }

        return sum_lr;
    }
};

int main() {
    Solution S;
    vector<int> nums = {7,5,8,5,6,4,3,3};
    int n = 8;
    int left = 2;
    int right = 6;
    cout << S.rangeSum(nums, n, left, right) << endl;
}