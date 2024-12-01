#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int i: nums) {
            pq.push(i);
            // kth largest -> make the length of pq k, so the smallest num in pq is kth largest
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        // make pq.top() the kth largest
        if (pq.size() > kth) pq.pop();
        return pq.top();
    }
private:
    int kth;
    // sort from less to large
    priority_queue<int, vector<int>, greater<int>> pq;
};

int main() {
    // KthLargest()
}