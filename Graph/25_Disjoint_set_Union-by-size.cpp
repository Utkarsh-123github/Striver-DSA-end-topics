#include<bits/stdc++.h>
using namespace std;

// TC = O(4*alpha) ~ O(1)

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
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
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

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    // check if 3 and 7 belong to same component at this point of time
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    ds.unionBySize(5,6);
    ds.unionBySize(3,7);
    // Now again check if 3 and 7 belong to same component at this point of time
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}