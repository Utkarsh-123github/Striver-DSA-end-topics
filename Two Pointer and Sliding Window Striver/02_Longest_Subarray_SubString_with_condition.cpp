// Pattern : Longest Subarray/Substring with condition
// For eg : Longest Subarray with sum less than or equal to k
// return maxLen

// Note : All array elements are positive integers

#include<bits/stdc++.h>
using namespace std;

// Brute approach : Generate all subarrays and check if sum is less than or equal to k and return maxLen
// Time : O(n^2)
// Space : O(1)

int bruteApproach(vector<int>arr,int k){
    int n = arr.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum<=k){
                maxLen = max(maxLen,j-i+1);
            }
            else break;
        }
    }
    return maxLen;
}

// Optimized approach : Sliding window
// Time : O(2n)
// Space : O(1)

int optimizedApproach(vector<int>arr,int k){
    int n = arr.size();
    int maxLen = 0;
    int l=0,r=0;
    int sum = 0;
    while(r<n){
        sum+=arr[r];
        if(sum<=k){
            maxLen = max(maxLen,r-l+1);
        }
        else{
            while(sum>k){
                sum-=arr[l];
                l++;
            }
        }
        r++;
    }
    return maxLen;
}

int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 15;
    cout<<optimizedApproach(arr,k);
    return 0;
}
