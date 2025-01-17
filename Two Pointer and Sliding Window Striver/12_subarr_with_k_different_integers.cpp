// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.
// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int k) {
    int n = nums.size();
    map<int,int>mpp;
    int l = 0, r = 0, cnt = 0;
    while(r<n){
        mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        if(mpp.size()<=k){
            cnt += r-l+1;
        }
        r++;
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int>& nums, int k){
    return solve(nums,k)-solve(nums,k-1);
}