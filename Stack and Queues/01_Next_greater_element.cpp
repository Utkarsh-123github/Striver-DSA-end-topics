// Given an array arr[] of integers, the task is to find the Next Greater Element for each element of the array in order of their appearance in the array.
// Note: The Next Greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1.
// Input: arr[] = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn’t exist, it is -1.



#include<bits/stdc++.h>
using namespace std;


// Brute force 
// TC = O(n^2)
// SC = O(1)
vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {

        // Check for the next greater element
        // in the rest of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }

    return result;
}

// Optimal Approach
// TC = O(n)
// SC = O(n)
vector<int>nge(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> result = nge(arr);
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}