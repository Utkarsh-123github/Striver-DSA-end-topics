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

int numberOfProvinces(vector<vector<int>> adj, int V){
    DisjointSet ds(V);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j] == 1 && i != j){
                ds.unionBySize(i,j);
            }
        }
    }

    
    int cnt = 0;
    for(int i=0;i<V;i++){
        if(ds.findUPar(i) == i)cnt++;
    }
    return cnt;
    
}