#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj, int startNode, vector<int>&ans,vector<int>&vis){
    vis[startNode] = 1;
    ans.push_back(startNode);
    for(auto it:adj[startNode]){
        if(!vis[it]){
            dfs(adj,it,ans,vis);
        }
    }
    return;
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    vector<int>ans;
    int n = adj.size();
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,i,ans,vis);
        }
    }
    return ans;
}