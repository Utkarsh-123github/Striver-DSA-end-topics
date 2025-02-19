#include<bits/stdc++.h>
using namespace std;

// TC = O(4*alpha) ~ O(1)

class DisjointSet {
    private:
        vector<int>rank,parent;
    public : 
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }

        // Path compression
        int findUPar(int node){
            if(node == parent[node])return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v){
            int upu = findUPar(u);
            int upv = findUPar(v);
            if(upu == upv)return;
            if(rank[upu] < rank[upv]){
                parent[upu] = upv;
            }
            else if(rank[upv] < rank[upu]){
                parent[upv] = upu;
            }
            else{
                parent[upv] = upu;
                rank[upu]++;
            }
        }

};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    // check if 3 and 7 belong to same component at this point of time
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    ds.unionByRank(5,6);
    ds.unionByRank(3,7);
    // Now again check if 3 and 7 belong to same component at this point of time
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
    
}