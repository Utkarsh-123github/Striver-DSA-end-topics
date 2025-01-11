// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

#include<bits/stdc++.h>
using namespace std;

// TC = O(3n) ~ O(n)
// SC = O(2n) ~ O(n)

vector<int>psi(vector<int>&arr){
    stack<int>st;
    int n = arr.size();
    vector<int>ans(n,-1);
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
    stack<int>st;
    int n = arr.size();
    vector<int>ans(n,n);
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

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    vector<int>prev = psi(heights);
    vector<int>next = nsi(heights);
    for(int i=0;i<n;i++){
        int left = prev[i];
        int right = next[i];
        int area = (right-left-1)*heights[i];
        maxArea = max(area,maxArea);
    }
    return maxArea;
}

int main(){
    vector<int>heights = {2,1,5,6,2,3};
    cout<<largestRectangleArea(heights);
}