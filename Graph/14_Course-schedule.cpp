// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// Approach : 
// We'll check if graph contains cycle, and if there is a cycle we'll return false.
// Now to check if graph contains cycle we'll perform topo sort and if topo sort answer exists then it means graph doesn't contains cycle so we'll return true

#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>indegree(numCourses,0);
        vector<int>adj[numCourses];
        for(auto it : prerequisites){
        adj[it[1]].push_back(it[0]);
        }

    for(int i=0;i<numCourses;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0)q.push(it);
        }
    }
    return topo.size()==numCourses ? true : false;
}