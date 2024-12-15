// Detemine max points that can be obtained from cards where there is an array representing different number of points of cards and we have to choose k cards from the array such that sum of points is maximum.

#include <bits/stdc++.h>
using namespace std;

// Approach : Sliding window
// 1. Find sum of first k elements and store it in sum.
// 2. Initialize maxSum = sum.
// 3. Traverse from k-1 to 0 and keep on adding arr[r] and subtracting arr[l] from sum and update maxSum.
// 4. Return maxSum.

// Eg : arr = {1,2,3,4,5,6,1}, k = 3
// sum = 1+2+3 = 6
// maxSum = 6
// l = 2, r = 6
// sum = 6-3+1 = 4
// maxSum = 6
// l = 1, r = 5
// sum = 4-2+6 = 8
// maxSum = 8
// l = 0, r = 4
// sum = 8-1+5 = 12
// maxSum = 12
// return 12


// TC : O(2*k)
// SC : O(1)



int maxScore(vector<int> &arr, int k)
{
    int l = k - 1;
    int n = arr.size();
    int r = n - 1;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int maxSum = sum;
    while (l >= 0)
    {
        sum -= arr[l];
        l--;
        sum += arr[r];
        r--;
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}