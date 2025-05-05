#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>&vis,vector<int> adj[],stack<int>&st){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int>&arr, vector<int>&vis, vector<int>adjRev[]){
    vis[node] = 1;
    arr.push_back(node);
    for(auto it:adjRev[node]){
        if(!vis[it]){
            dfs2(it,arr,vis,adjRev);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>>ans;
    stack<int>st;
    vector<int>vis(n,0);
    vector<int>adj[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }

    vector<int>adjRev[n];
    for(int i=0;i<n;i++){
        vis[i] = 0;
        for(auto it:adj[i]){
            adjRev[it].push_back(i);
        }
    }

    while(!st.empty()){
        vector<int>arr;
        int node = st.top();
        st.pop();
        if(!vis[node]){
            dfs2(node,arr,vis,adjRev);
        }
        ans.push_back(arr);
    }
    return ans;
}