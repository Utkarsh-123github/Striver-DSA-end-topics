#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>&adj, vector<int>&vis, int src){
    
    vis[src] = 1;
    // store source node and the parent node in the queue
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parentNode = q.front().second;
        q.pop();
        // go to all adjacent nodes 
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push({adjNode,node});
            }
            // if adjacent node is visited and adjacent node is not it's own parent node
            else if(parentNode != adjNode)return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(adj,vis,i))return true;
        }
    }
    return false;
    
}