// Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.
// Follow up: Don't solve it using the inbuilt sort function.
// Examples :

// Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
// Output:  7
// Explanation: 3rd smallest element in the given array is 7.

// We'll solve this using max heap
// In max heap largest element is at the top

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int>pq;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

// TC = O(nlogk)
// SC = O(k)