// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// Example 1:

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.
// Example 3:

// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

// Optimal Approach
// TC = O(n)
// SC = O(n)

#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& arr) {
    int n = arr.size();
    stack<int>st;
    for(int i=0;i<n;i++){
        if(arr[i]>0 || st.empty()){
            st.push(arr[i]);
        }
        else{
            while(!st.empty() && st.top()>0 && st.top() < abs(arr[i])){
                st.pop();
            }
            if(!st.empty() && st.top() == abs(arr[i])){
                st.pop();
            }
            else{
                if(st.empty() || st.top()<0){
                    st.push(arr[i]);
                }
            }
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>arr = {5,10,-5};
    vector<int>ans = asteroidCollision(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}