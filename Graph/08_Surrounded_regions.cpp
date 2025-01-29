// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Link : https://leetcode.com/problems/surrounded-regions/description/

#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<char>>&board , vector<vector<int>>&vis, int row, int col){
    vis[row][col] = 1;
    int m = board.size();
    int n = board[0].size();
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto [dr,dc] : directions){
        int nr = row + dr;
        int nc = col + dc;
        if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc] == 'O' && !vis[nr][nc]){
            dfs(board,vis,nr,nc);
        }
    }
    return;
}
void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    for(int j=0;j<n;j++){
        if(board[0][j] == 'O' && !vis[0][j]){
            dfs(board,vis,0,j);
        }
    }
    
    for(int j=0;j<n;j++){
        if(board[m-1][j] == 'O' && !vis[m-1][j]){
            dfs(board,vis,m-1,j);
        }
    }

    for(int i=0;i<m;i++){
        if(board[i][0] == 'O' && !vis[i][0]){
            dfs(board,vis,i,0);
        }
    }
    for(int i=0;i<m;i++){
        if(board[i][n-1] == 'O' && !vis[i][n-1]){
            dfs(board,vis,i,n-1);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                board[i][j] = 'X';
            }
        }
    }
}

