// Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).

// Examples :

// Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
// Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
// Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
// Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
// Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].

#include<bits/stdc++.h>
using namespace std;

// We'll use min Heap to store every matrix element in the heap and then transfer it to ans array
// TC = O(n^2*logn)
// SC = O(n^2)

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    //code here
    priority_queue<int,vector<int>,greater<int>>pq;
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(arr[i][j]);
        }
    }
    vector<int>ans;
    while(pq.size()>0){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

