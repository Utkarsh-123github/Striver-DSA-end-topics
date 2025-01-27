// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1.

// Example 1:

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> p;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>>vis(m,vector<int>(n,0));
    vector<vector<int>>ans(m,vector<int>(n,0));
    queue<p>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 0){
                vis[i][j] = 1;
                q.push({{i,j},0});
            }
        }
    }
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int distance = q.front().second;
        ans[row][col] = distance;
        q.pop();
        for(auto [dr,dc] : directions){
            int nr = row + dr;
            int nc = col + dc;
            if(nr>=0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0){
                vis[nr][nc] = 1;
                q.push({{nr,nc},distance + 1});
            }
        }
    }
    return ans;

}