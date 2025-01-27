// Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

// Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// [
//  [1, 0, 1],
//  [0, 1, 0],
//  [1, 0, 1]
// ]

// Output:
// 2
// Explanation:
// The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.

#include<bits/stdc++.h>
using namespace std;

void dfs(int start, vector<int>adj[],vector<int>&vis){
    vis[start] = 1;
    for(auto it:adj[start]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
    return;
}

int numProvinces(vector<vector<int>> adj, int V) {
    // code here
    vector<int>adjList[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j] == 1 && i != j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    int cnt = 0;
    vector<int>vis(V+1,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjList,vis);
        }
    }
    return cnt;
}