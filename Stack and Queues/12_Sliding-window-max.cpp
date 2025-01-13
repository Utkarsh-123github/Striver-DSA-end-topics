// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

#include<bits/stdc++.h>
using namespace std;

// Brute approach
// TC = O((n-k)*k)
// SC = O(1)

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>ans;
    int n = nums.size();
    for(int i=0;i<n-k+1;i++){
        int maxi = nums[i];
        for(int j=0;j<k;j++){
            maxi = max(maxi,nums[i+j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

// Optimal Approach
// Using deque (Doubly ended queue)
// TC = O(2n)
// SC = O(n-k)

vector<int>maxSlidingWindow2(vector<int>&nums, int k){
    // deque to store indexes
    deque<int>dq;
    vector<int>ans;
    int n = nums.size();
    for(int i=0;i<n;i++){
        // Remove indexes from the deque from front which are not in the window size
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }

        // Remove elements from the back while they are smaller than the current element
        while(!dq.empty() && nums[dq.back()] < nums[i] ){
            dq.pop_back();
        }

        // Add current element's index to the deque
        dq.push_back(i);

        // Once the first window is formed, add the maximum(front of the deque) to the ans
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }

    }
    return ans;
}


