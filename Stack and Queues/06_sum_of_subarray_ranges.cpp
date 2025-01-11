// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0 
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

#include<bits/stdc++.h>
using namespace std;

// Optimal approach
// TC = O(5n) ~ O(n)
// SC = O(4n) ~ O(n)
vector<int>psi(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int>nsi(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = n;
        }
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int>ngi(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = n;
        }
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int>pgi(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int>arr = {1,2,3};
    vector<int>prevSmall = psi(arr);
    vector<int>nextSmall = nsi(arr);
    vector<int>prevGreater = pgi(arr);
    vector<int>nextGreater = ngi(arr);
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<prevSmall[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<nextSmall[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<prevGreater[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<nextGreater[i]<<" ";
    }

    int minSum = 0;
    int maxSum = 0;
    for(int i=0;i<n;i++){
        int lSmall = i - prevSmall[i];
        int rSmall = nextSmall[i] - i;
        minSum += lSmall*rSmall*arr[i];
        int lGreat = i-prevGreater[i];
        int rGreat = nextGreater[i] - i;
        maxSum += lGreat*rGreat*arr[i];
    }
    cout<<maxSum-minSum;


}