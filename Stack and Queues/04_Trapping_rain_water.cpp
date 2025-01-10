// Very Very important question 
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// For question diagram visit : https://leetcode.com/problems/trapping-rain-water/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1
// Using prefixMax and suffixMax array
// TC = O(2n)
// SC = O(2n)
int trap(vector<int>& height) {
    int n = height.size();
    vector<int>prefixMax(n,-1);
    vector<int>suffixMax(n,-1);
    prefixMax[0] = height[0];
    for(int i=1;i<n;i++){
        prefixMax[i] = max(prefixMax[i-1],height[i]);
    }
    suffixMax[n-1] = height[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i+1],height[i]);
    }

    int total = 0;
    for(int i=0;i<n;i++){
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        if(height[i] < leftMax && height[i] < rightMax){
            total += min(leftMax,rightMax) - height[i];
        }
    }
    return total;
}

// Approach 2 
// Using two pointer
// TC = O(2n)
// SC = O(1)

// Take 2 pointers l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively. Take two variables leftMax and rightMax and initialize them to 0. If height[l] is less than or equal to height[r] then if leftMax is less than height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the right i.e l++. If height[r] is less than height[l], then now we are dealing with the right block. If height[r] is greater than rightMax, then update rightMax to height[r] else add rightMax-height[r] to the final answer. Now move r to the left. Repeat these steps till l and r crosses each other.

// Intuition: We need a minimum of leftMax and rightMax.So if we take the case when height[l]<=height[r] we increase l++, so we can surely say that there is a block with a height more than height[l] to the right of l. And for the same reason when height[r]<=height[l] we can surely say that there is a block to the left of r which is at least of height[r]. So by traversing these cases and using two pointers approach the time complexity can be decreased without using extra space.

int trap2(vector<int>&arr){
    int n = arr.size();
    int total = 0, leftMax = 0, rightMax = 0, l = 0, r = n-1;
    while(l<r){
        if(arr[l] <= arr[r]){
            if(leftMax > arr[l]){
                total += leftMax - arr[l];
            }
            else leftMax = arr[l];
            l = l+1;
        }
        else{
            if(rightMax > arr[r]){
                total += rightMax - arr[r];
            }
            else rightMax = arr[r];
            r = r-1;
        }
    }
    return total;
}

int main() {
    vector<int>height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap2(height)<<endl;
}