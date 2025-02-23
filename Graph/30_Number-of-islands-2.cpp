// You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
// Note : An island means group of 1s such that they share a common side.

 

// Example 1:

// Input: n = 4
// m = 5
// k = 4
// A = {{1,1},{0,1},{3,3},{3,4}}

// Output: 1 1 2 2
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  00000
//     01000
//     00000
//     00000
// 2.  01000
//     01000
//     00000
//     00000
// 3.  01000
//     01000
//     00000
//     00010
// 4.  01000
//     01000
//     00000
//     00011

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
    vector<int>size,parent;
    public:
    DisjointSet (int n){
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
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt = 0;
        vector<int>ans;
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            vector<int>dr = {-1,1,0,0};
            vector<int>dc = {0,0,-1,1};
            for(int i=0;i<4;i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                if(adjr >=0 && adjr<n && adjc>=0 && adjc<m){
                    if(vis[adjr][adjc] == 1){
                        int node = row*m + col;
                        int adjNode = adjr*m + adjc;
                        if(ds.findUPar(node) != ds.findUPar(adjNode)){
                            cnt--;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};