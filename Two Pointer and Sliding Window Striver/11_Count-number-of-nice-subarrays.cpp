// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

#include<bits/stdc++.h>
using namespace std;

int fn(vector<int>&arr, int k){
    int n = arr.size();
    int l=0,r=0,cnt=0;
    int oddcnt = 0;
    while(r<n){
        if(arr[r] % 2 == 1){
            oddcnt++;
        }
        while(oddcnt > k){
            if(arr[l] % 2 != 0){
                oddcnt--;
            }
            l++;
        }
        if(oddcnt <= k){
            cnt = cnt + r-l+1;
        }
        r++;
    }
    return cnt;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return fn(nums,k) - fn(nums,k-1);
}

// TC = O(n)
// SC = O(1)

int main(){
    vector<int>arr = {2,2,2,1,2,2,1,2,2,2};
    cout<<numberOfSubarrays(arr,2);
    return 0;
}