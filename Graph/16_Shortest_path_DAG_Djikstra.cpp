#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<pair<int,int>>adj[V];
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v,w});
    }
    
    vector<int>dist(V,1e9);
    dist[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int adjNode = it.first;
            int wt = it.second;
            if(wt + distance < dist[adjNode]){
                dist[adjNode] = wt + distance;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    for(int i=0;i<dist.size();i++){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
    }
    return dist;
}