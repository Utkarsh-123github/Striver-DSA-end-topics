// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

#include<bits/stdc++.h>
using namespace std;

//----------Start of Brute force approach-----------//

void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row, int col, int& area){
    vis[row][col] = 1;
    int n = grid.size();
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    for(auto [dr,dc] : directions){
        int nr = row + dr;
        int nc = col + dc;
        if(nr >=0 && nr < n && nc>=0 && nc<n && vis[nr][nc] == 0 && grid[nr][nc] == 1){
            area = area + 1;
            dfs(grid,vis,nr,nc,area);
        }
    }
}

int findArea(vector<vector<int>>&grid){
    int n = grid.size();
    vector<vector<int>>vis(n,vector<int>(n,0));
    int area = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j] == 0 && grid[i][j] == 1){
                int newArea = 1;
                dfs(grid,vis,i,j,newArea);
                area = max(area,newArea);
            }
        }
    }
    return area;
}
int largestIsland(vector<vector<int>>& grid) {
    queue<pair<int,int>>q;
    int n = grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                q.push({i,j});
            }
        }
    }

    if(q.size() == 0)return n*n;

    int ans = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int i = it.first;
        int j = it.second;
        grid[i][j] = 1;
        int area = findArea(grid);
        ans = max(area,ans);
        grid[i][j] = 0;
    }
    return ans;
}


//------------- End of brute approach-------------//