//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:
// Input: nums = [1,1,0,0,1,1,1,0], k = 2
// Output: 7
// Explanation: [1,1,0,0,1,1,1,1]
// Explanation: We flip the zero at index 2 and 3 to get the the maximum number of consecutive 1's.

#include <bits/stdc++.h>
using namespace std;

// Approach : Sliding window
// 1. Initialize l = 0, r = 0, n = nums.size(), zeroCount = 0, maxLen = 0.
// 2. Traverse the array and if nums[r] == 0, increment zeroCount.
// 3. If zeroCount > k, then increment l and if nums[l] == 0, decrement zeroCount.
// 4. Update maxLen = max(maxLen,r-l+1).
// 5. Return maxLen.

// TC : O(n)
// SC : O(1)

int longestOnes(vector<int> &nums, int k)
{
    int l = 0;
    int r = 0;
    int n = nums.size();
    int zeroCount = 0;
    int maxLen = 0;
    while (r < n)
    {
        if (nums[r] == 0)
        {
            zeroCount++;
        }
        if (zeroCount > k)
        {
            if (nums[l] == 0)
            {
                zeroCount--;
            }
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0};
    int k = 2;
    cout << longestOnes(nums, k) << endl;
    return 0;
}
