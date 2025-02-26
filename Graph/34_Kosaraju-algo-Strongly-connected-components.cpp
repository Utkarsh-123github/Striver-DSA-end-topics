// Algorithm: 

// The algorithm steps are as follows:

// Sort all the nodes according to their finishing time:
// To sort all the nodes according to their finishing time, we will start DFS from node 0 and while backtracking in the DFS call we will store the nodes in a stack data structure. The nodes in the last SCC will finish first and will be stored in the last of the stack. After the DFS gets completed for all the nodes, the stack will be storing all the nodes in the sorted order of their finishing time.
// Reverse all the edges of the entire graph:
// Now, we will create another adjacency list and store the information of the graph in a reversed manner.
// Perform the DFS and count the no. of different DFS calls to get the no. of SCC:
// Now, we will start DFS from the node which is on the top of the stack and continue until the stack becomes empty. For each individual DFS call, we will increment the counter variable by 1. We will get the number of SCCs by just counting the number of individual DFS calls as in each individual DFS call, all the nodes of a particular SCC get visited.
// Finally, we will get the number of SCCs in the counter variable. If we want to store the SCCs as well, we need to store the nodes in some array during each individual DFS call in step 3.

#include<bits/stdc++.h>
using namespace std;
void dfs(int& node, vector<vector<int>>&adj, vector<int>&vis, stack<int>&st){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}

void dfs2(int& node, vector<vector<int>>&adjRev, vector<int>&vis){
    vis[node] = 1;
    for(auto it:adjRev[node]){
        if(!vis[it]){
            dfs2(it,adjRev,vis);
        }
    }
}

int kosaraju(vector<vector<int>> &adj) {
    int n = adj.size();
    // Step 1: Sort all the edges according to finishing time
    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    
    // Step 2: Reverse the graph also side by side make the visited array again zero
    // So that we can reuse it
    vector<vector<int>>adjRev(n);
    for(int i=0;i<n;i++){
        vis[i] = 0;
        for(auto it:adj[i]){
            adjRev[it].push_back(i);
        }
    }
    
    // Step 3: Do dfs
    int cnt = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            cnt++;
            dfs2(node,adjRev,vis);
        }
    }
    
    return cnt;
}