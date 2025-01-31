// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.

// The algorithm steps are as follows:

// -> We will traverse the graph component-wise using the DFS technique. 

// -> Make sure to carry two visited arrays in the DFS call. One is a visited array(vis) and the other is a path-visited(pathVis) array. The visited array keeps a track of visited nodes, and the path-visited keeps a track of visited nodes in the current traversal only. 

// -> While making a DFS call, at first we will mark the node as visited in both the arrays and then will traverse through its adjacent nodes. Now, there may be either of the three cases:
//  Case 1: If the adjacent node is not visited, we will make a new DFS call recursively with that particular node.
//  Case 2: If the adjacent node is visited and also on the same path(i.e marked visited in the pathVis array), we will return true, because it means it has a cycle, thereby the pathVis was true. Returning true will mean the end of the function call, as once we have got a cycle, there is no need to check for further adjacent nodes. 
//  Case 3: If the adjacent node is visited but not on the same path(i.e not marked in the pathVis array), we will continue to the next adjacent node, as it would have been marked as visited in some other path, and not on the current one.

// -> Finally, if there are no further nodes to visit, we will unmark the current node in the pathVis array and just return false. Then we will backtrack to the previous node with the returned value. The point to remember is, while we enter we mark both the pathVis and vis as true, but at the end of traversal to all adjacent nodes, we just make sure we unmark the pathVis and still keep the vis marked as true, as it will avoid future extra traversal calls. 

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>&adj,vector<int>&vis, int start, vector<int>&pathVis){
    vis[start] = 1;
    pathVis[start] = 1;
    for(auto it:adj[start]){
        if(!vis[it]){
            if(dfs(adj,vis,it,pathVis) == true)return true;
        }
        else if(pathVis[it]){
            return true;
        }
    }
    pathVis[start] = 0;
    return false;
}

bool isCyclic(int n, vector<vector<int>> adj) {
    // code here
    vector<int>vis(n,0);
    vector<int>pathVis(n,0);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(adj,vis,i,pathVis) == true)return true;
        }
    }
    return false;
}