#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        typedef pair<int,pair<int,int>> p;
        int minimumEffortPath(vector<vector<int>>& heights) {
            int n = heights.size();
            int m = heights[0].size();
            vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
            vector<vector<int>>arr(n,vector<int>(m,1e9));
            arr[0][0] = 0;
            queue<p>q;
            q.push({0,{0,0}});
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int effort = it.first;
                int row = it.second.first;
                int col = it.second.second;
                for(auto [dr,dc] : directions){
                    int nr = row + dr;
                    int nc = col + dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        int newEffort = max(effort,abs(heights[nr][nc] - heights[row][col]));
                        if(newEffort < arr[nr][nc]){
                            arr[nr][nc] = newEffort;
                            q.push({newEffort,{nr,nc}});
                        }
                    }
                }
            }
            return arr[n-1][m-1];
        }
    };