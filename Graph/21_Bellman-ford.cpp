#include<bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int>dist(V,1e8);
    dist[src] = 0;
    // Perform iterations V-1 times
    for(int i=0;i<V-1;i++){
        for(auto it : edges){
            int node = it[0];
            int adjNode = it[1];
            int wt = it[2];
            if(dist[node] != 1e8 && dist[node] + wt < dist[adjNode]){
                dist[adjNode] = dist[node] + wt;
            }
        }
    }
    
    // Perform last iteration to check negative cycle and if it exists then return an array 
    // with only element as -1
    
    for(auto it : edges){
        int node = it[0];
        int adjNode = it[1];
        int wt = it[2];
        if(dist[node] != 1e8 && dist[node] + wt < dist[adjNode]){
            return {-1};
        }
    }
    
    return dist;
}