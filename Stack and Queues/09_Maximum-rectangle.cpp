// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Visit : https://leetcode.com/problems/maximal-rectangle/description/

// Approach : For each row we will make the scenario similar to Largest rectangle in Histogram
// TC = O(n) (We are not considering the time taken to traverse the matrix)
// SC = O(n)

#include<bits/stdc++.h>
using namespace std;

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
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    if(n == 0)return 0;
    vector<int>heights(m,0);
    int maxArea = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            heights[j] = (matrix[i][j] == '1') ? heights[j]+1 : 0;
        }
        maxArea = max(maxArea,largestRectangleArea(heights));
    }
    return maxArea;

}
