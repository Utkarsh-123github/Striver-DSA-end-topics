#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<pair<int,int>>adj[n+1];
            for(auto it : times){
                adj[it[0]].push_back({it[1],it[2]});
            }
            vector<int>cost(n+1,INT_MAX);
            cost[k] = 0;
            cost[0] = 0;
            queue<pair<int,int>>q;
            q.push({0,k});
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int t = it.first;
                int node = it.second;
                for(auto x : adj[node]){
                    int newT = x.second;
                    int adjNode = x.first;
                    if(t + newT < cost[adjNode]){
                        cost[adjNode] = t + newT;
                        q.push({cost[adjNode],adjNode});
                    }
    
                }
            }
            sort(cost.begin(),cost.end());
            return cost[n] == INT_MAX ? -1 : cost[n];
    
        }
    };