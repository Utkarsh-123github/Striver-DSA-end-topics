#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int x = n;
        vector<pair<int,int>>adj[x];
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>prices(n,1e9);
        prices[src] = 0;
        queue<vector<int>>q;
        q.push({src,0,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it[0];
            int price = it[1];
            int steps = it[2];
            for(auto i : adj[node]){
                int newNode = i.first;
                int amount = i.second;
                if(prices[newNode] > price + amount && steps <= k){
                    prices[newNode] = price + amount;
                    q.push({newNode,prices[newNode],steps+1});
                }
            }
        }
        if(prices[dst] == 1e9)return -1;
        return prices[dst];


    }
};