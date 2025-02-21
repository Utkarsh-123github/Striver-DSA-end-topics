// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Here we'll use disjoint sets
// We'l l count the number of connected components and return cnt - 1;
// Edge case : If adjList size is less than n-1 then return -1 bcoz there are less cables in order to connect all the components

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
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
        else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};
class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V){
        DisjointSet ds(V);
        for(auto it : adj){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u,v);
        }
    
        
        int cnt = 0;
        for(int i=0;i<V;i++){
            if(ds.findUPar(i) == i)cnt++;
        }
        return cnt;
    
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int s = connections.size();
        if(s<n-1)return -1;
        int cnt = numProvinces(connections,n);
        return cnt>0 ? cnt-1 : 0;
    }
};