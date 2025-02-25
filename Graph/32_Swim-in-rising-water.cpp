// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

// The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

// Example 1:


// Input: grid = [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.
// Example 2:


// Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation: The final route is shown.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> p;
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>>dist(n,vector<int>(n,1e9));
    dist[0][0] = grid[0][0];
    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({grid[0][0],{0,0}});
    while(!pq.empty()){
        auto [time,rowCol] = pq.top();
        pq.pop();
        auto [row,col] = rowCol;
        for(auto [dr,dc] : directions){
            int nr = row + dr;
            int nc = col + dc;
            if(nr>=0 && nr<n && nc>=0 && nc<n){
                if(grid[nr][nc] <= grid[row][col] && time < dist[nr][nc]){
                    dist[nr][nc] = time;
                    pq.push({dist[nr][nc],{nr,nc}});
                }
                else if(dist[nr][nc] == 1e9){
                    dist[nr][nc] = max(grid[nr][nc],time);
                    pq.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
    }

    return dist[n-1][n-1];

}