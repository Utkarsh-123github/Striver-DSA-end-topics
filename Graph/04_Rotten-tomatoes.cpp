// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>>rotten;
    int m = grid.size();
    int n = grid[0].size();
    int totalTomatoes = 0;
    int minutes = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] != 0)totalTomatoes++; 
            if(grid[i][j] == 2){
                rotten.push({i,j});
            }
        }
    }
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int rottenTomatoCnt = 0;
    while(!rotten.empty()){
        int k = rotten.size();
        rottenTomatoCnt += k;
        while(k--){
            int row = rotten.front().first;
            int col = rotten.front().second;
            rotten.pop();
            for(auto [dr,dc] : directions){
                int nr = row + dr;
                int nc = col + dc;
                if(nr<0 || nc<0 || nr>=m || nc>=n || grid[nr][nc] != 1)continue;
                grid[nr][nc] = 2;
                rotten.push({nr,nc});
            }
        }
        if(!rotten.empty())minutes++;
    }
    return totalTomatoes == rottenTomatoCnt ? minutes : -1;

}