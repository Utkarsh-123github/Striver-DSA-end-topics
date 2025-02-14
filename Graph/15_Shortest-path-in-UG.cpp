#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    // code here
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int adjNode : adj[node]) {
            if (dist[adjNode] == INT_MAX) {
                dist[adjNode] = dist[node] + 1;
                q.push(adjNode);
            }
        }
    }
    
    for (int &d : dist) {
        if (d == INT_MAX) d = -1;
    }
    
    return dist;
}