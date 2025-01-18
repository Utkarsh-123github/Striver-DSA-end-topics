// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 

// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3

// Output: [1,2,3,4]

// Example 2:

// Input: arr = [1,1,2,3,4,5], k = 4, x = -1

// Output: [1,1,2,3]

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ppi;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int>ans;
    priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
    for(int i=0;i<arr.size();i++){
        pq.push({abs(arr[i]-x),arr[i]});
    }
    int cnt = 0;
    while(cnt<k){
        auto it = pq.top();
        pq.pop();
        ans.push_back(it.second);
        cnt++;
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// TC = O(nlogn)
// SC = O(n)