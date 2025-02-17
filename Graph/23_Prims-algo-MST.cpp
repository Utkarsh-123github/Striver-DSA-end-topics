// Approach: 
// In order to implement Prim’s algorithm, we will be requiring an array(visited array) and a priority queue that will essentially represent a min-heap. We need another array(MST) as well if we wish to store the edge information of the minimum spanning tree.

// The algorithm steps are as follows:

// Priority Queue(Min Heap): The priority queue will be storing the pairs (edge weight, node). We can start from any given node. Here we are going to start from node 0 and so we will initialize the priority queue with (0, 0). If we wish to store the mst of the graph, the priority queue should instead store the triplets (edge weight, adjacent node, parent node) and in that case, we will initialize with (0, 0, -1).

// Visited array: All the nodes will be initially marked as unvisited.

// sum variable: It will be initialized with 0 and we wish that it will store the sum of the edge weights finally.

// MST array(optional): If we wish to store the minimum spanning tree(MST) of the graph, we need this array. This will store the edge information as a pair of starting and ending nodes of a particular edge.

// We will first push edge weight 0, node value 0, and parent -1 as a triplet into the priority queue to start the algorithm.
// Note: We can start from any node of our choice. Here we have chosen node 0.
// Then the top-most element (element with minimum edge weight as it is the min-heap we are using) of the priority queue is popped out.
// After that, we will check whether the popped-out node is visited or not.
// If the node is visited: We will continue to the next element of the priority queue.
// If the node is not visited: We will mark the node visited in the visited array and add the edge weight to the sum variable. If we wish to store the mst, we should insert the parent node and the current node into the mst array as a pair in this step.
// Now, we will iterate on all the unvisited adjacent nodes of the current node and will store each of their information in the specified triplet format i.e. (edge weight, node value, and parent node) in the priority queue.
// We will repeat steps 2, 3, and 4 using a loop until the priority queue becomes empty.
// Finally, the sum variable should store the sum of all the edge weights of the minimum spanning tree.
// Note: Points to remember if we do not wish to store the mst(minimum spanning tree) for the graph and are only concerned about the sum of all the edge weights of the minimum spanning tree:

// First of all, we will not use the triplet format instead, we will just use the pair in the format of (edge weight, node value). Basically, we do not need the parent node.
// In step 3, we need not store anything in the mst array and we need not even use the mst array in our whole algorithm as well.
// Intuition:
// The intuition of this algorithm is the greedy technique used for every node. If we carefully observe, for every node, we are greedily selecting its unvisited adjacent node with the minimum edge weight(as the priority queue here is a min-heap and the topmost element is the node with the minimum edge weight). Doing so for every node, we can get the sum of all the edge weights of the minimum spanning tree and the spanning tree itself(if we wish to) as well.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    typedef pair<int,int> p;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        int sum = 0;
        vector<int>vis(V,0);
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if(vis[node] == 1)continue;
            vis[node] = 1;
            sum += wt;
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!vis[adjNode]){
                    pq.push({edgeWt,adjNode});
                }
            }
        }
        return sum;
    }
};


