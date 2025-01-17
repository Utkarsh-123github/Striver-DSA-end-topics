// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4


// We'll solve this question without sorting the array using min heap
// In min heap the smallest element is at the top

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>>pq;
    int n = nums.size();
    for(int i=0;i<n;i++){
        pq.push(nums[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

// TC = O(nlogk)
// SC = O(k)

int main(){
    vector<int>arr = {3,2,1,5,6,4};
    int k = 3;
    cout<<findKthLargest(arr,k)<<endl;
    return 0;
}