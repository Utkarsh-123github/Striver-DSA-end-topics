#include<bits/stdc++.h>
using namespace std;

void bfs(int startNode, vector<vector<int>>&adj, vector<int>&vis, vector<int>&ans){
    queue<int>q;
    q.push(startNode);
    vis[startNode] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node] = 1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return;
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Graph adjacency list representation
    vector<vector<int>> adjList(nodes);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line for directed graphs
    }

    // To keep track of visited nodes
    vector<int> visited(nodes, 0);

    // Perform BFS for every component
    vector<int>ans;
    cout << "BFS traversal of the graph:" << endl;
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            bfs(i,adjList,visited,ans);
            cout << endl; // Separate components
        }
    }

    return 0;
}