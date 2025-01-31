// Note: In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

// Example 1:

// Input: V = 6, E = 6

// Output: 5, 4, 2, 3, 1, 0
// Explanation: A graph may have multiple topological sortings. 
// The result is one of them. The necessary conditions 
// for the ordering are:
// According to edge 5 -> 0, node 5 must appear before node 0 in the ordering.
// According to edge 4 -> 0, node 4 must appear before node 0 in the ordering.
// According to edge 5 -> 2, node 5 must appear before node 2 in the ordering.
// According to edge 2 -> 3, node 2 must appear before node 3 in the ordering.
// According to edge 3 -> 1, node 3 must appear before node 1 in the ordering.
// According to edge 4 -> 1, node 4 must appear before node 1 in the ordering.

// The above result satisfies all the necessary conditions. 
// [4, 5, 2, 3, 1, 0] is also one such topological sorting 
// that satisfies all the conditions.

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,vector<int>&vis,stack<int>&st,int start){
    vis[start] = 1;
    for(auto it:adj[start]){
        if(!vis[it]){
            dfs(adj,vis,st,it);
        }
    }
    st.push(start);
    return;
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
    // Your code here
    stack<int>st;
    int n = adj.size();
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,vis,st,i);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}