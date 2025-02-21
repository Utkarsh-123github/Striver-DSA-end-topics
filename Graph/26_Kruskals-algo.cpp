// Approach: 
// We will be implementing Kruskal’s algorithm using the Disjoint Set data structure that we have previously learned.

// Now, we know Disjoint Set provides two methods named findUPar()(This function helps to find the ultimate parent of a particular node) and Union(This basically helps to add the edges between two nodes). To know more about these functionalities, do refer to the article on Disjoint Set.

// The algorithm steps are as follows:

// -> First, we need to extract the edge information(if not given already) from the given adjacency list in the format of (wt, u, v) where u is the current node, v is the adjacent node and wt is the weight of the edge between node u and v and we will store the tuples in an array.

// ->Then the array must be sorted in the ascending order of the weights so that while iterating we can get the edges with the minimum weights first.

// -> After that, we will iterate over the edge information, and for each tuple, we will apply the  following operation:
//     -> First, we will take the two nodes u and v from the tuple and check if the ultimate parents of both nodes are the same or not using the findUPar() function provided by the Disjoint Set data structure.
//     -> If the ultimate parents are the same, we need not do anything to that edge as there already exists a path between the nodes and we will continue to the next tuple.
//     -> If the ultimate parents are different, we will add the weight of the edge to our final answer(i.e. mstWt variable used in the following code) and apply the union operation(i.e. either unionBySize(u, v) or unionByRank(u, v)) with the nodes u and v. The union operation is also provided by the Disjoint Set.

// -> Finally, we will get our answer (in the mstWt variable as used in the following code) successfully.

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private : 
    vector<int>size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node])return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int upu = findUPar(u);
        int upv = findUPar(v);
        if(upu == upv)return;
        if(size[upu] < size[upv]){
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else{
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};
typedef pair<int,pair<int,int>> p;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<p>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int node = i;
                int adjNode = it[0];
                int wt = it[1];
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstWt = 0;
        for(int i=0;i<edges.size();i++){
            int wt = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};