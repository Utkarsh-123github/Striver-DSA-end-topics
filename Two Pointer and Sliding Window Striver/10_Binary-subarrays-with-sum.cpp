// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays : [{1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1}]


#include<bits/stdc++.h>
using namespace std;

// Brute approach
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            if(sum == goal)cnt++;
        }
    }
    return cnt;
}

// TC = O(n^2)
// SC = O(1)

// Optimal approach

int helper(vector<int>&nums,int goal){
    // This helper function count subarrays with sum <= goal
    int l = 0, r = 0, count = 0, n = nums.size();
    int sum = 0;
    if(goal<0)return 0;
    while(r<n){
        sum += nums[r];
        while(sum>goal){
            sum -= nums[l];
            l++;
        }
        if(sum <= goal){
            count = count + r-l+1;
        }
        r++;
    }
    return count;
}
int numSubarraysWithSums(vector<int>& nums, int goal) {
    return helper(nums,goal) - helper(nums,goal-1);
}

