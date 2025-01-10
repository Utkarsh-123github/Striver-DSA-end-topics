#include<bits/stdc++.h>
using namespace std;

// Brute approach
// TC = O(n^2)
// SC = O(1)

int sumSubarrayMins(vector<int>& arr) {
    int total = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        int mini = INT_MAX;
        for(int j = i;j<n;j++){
            mini = min(mini,arr[j]);
            total += mini;
        }
    }
    return total;
}

// Optimal Approach 
// TC = O(3n)
// SC = O(2n)
int mod = 1e9 + 7;
vector<int>psi(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
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
        while(!st.empty() && arr[st.top()]>=arr[i]){
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
int sumSubarrayMins2(vector<int>& arr) {
    int n = arr.size();
    vector<int>prev = psi(arr);
    vector<int>next = nsi(arr);
    int total = 0;
    for(int i=0;i<n;i++){
        int leftSubarrays = i-prev[i];
        int rightSubarrays = next[i]-i;
        total = (total + (1LL*arr[i]*leftSubarrays*rightSubarrays)%mod)%mod ;
    }
    return total;
}


int main(){
    vector<int>arr = {3,1,2,4};
    cout<<sumSubarrayMins2(arr);
    return 0;
}