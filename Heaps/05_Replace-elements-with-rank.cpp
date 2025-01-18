// Given an array arr of N integers, the task is to replace each element of the array by its rank in the array. The rank of an element is defined as the distance between the element with the first element of the array when the array is arranged in ascending order. If two or more are same in the array then their rank is also the same as the rank of the first occurrence of the element. 

// Example 1:

// Input:
// N = 6
// arr = [20, 15, 26, 2, 98, 6]
// Output:
// 4, 3, 5, 1, 6, 2
// Explanation:
// After sorting, array becomes {2,6,15,20,26,98}
// Rank(2) = 1 (at index 0) 
// Rank(6) = 2 (at index 1) 
// Rank(15) = 3 (at index 2) 
// Rank(20) = 4 (at index 3) and so on..

#include<bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int N){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(int i=0;i<N;i++){
        pq.push({arr[i],i});
    }
    int rank = 0, prev = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.first != prev){
            rank++;
            prev = it.first;
        }
        arr[it.second] = rank;
    }
    return arr;

}

// TC = O(nlogn) + O(n)
// SC = O(1)