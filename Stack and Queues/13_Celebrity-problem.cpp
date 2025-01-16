// A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.

// Examples:

// Input: mat[][] = [[0 1 0], [0 0 0], [0 1 0]]
// Output: 1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
// Input: mat[][] = [[0 1], [1 0]]
// Output: -1
// Explanation: The two people at the party both know each other. None of them is a celebrity.

#include<bits/stdc++.h>
using namespace std;

// Approach - 1
// We'll make two arrays
// First array will indicate how many knows me
// Second array will indicate how many I know
// if knowsMe[i] == n-1 && iKnow[i] == 0 then i will be the celebrity

int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    vector<int>knowsMe(n,0);
    vector<int>iKnow(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1){
                iKnow[i]++;
                knowsMe[j]++;
            }
        }
    }
    int ans = -1;
    for(int i=0;i<n;i++){
        if(knowsMe[i] == n-1 && iKnow[i] == 0){
            ans = i;
        }
    }
    return ans;
}

// Optimal Approach
// TC = O(2n)
// SC = O(1)
// Approach Dry run is done in copy

int celebrity2(vector<vector<int> >& mat) {
    int n = mat.size();
    int top = 0;
    int bottom = n-1;
    while(top<bottom){
        if(mat[top][bottom] == 1){
            top++;
        }
        else if(mat[bottom][top] == 1){
            bottom--;
        }
        else {
            top++;
            bottom--;
        }
    }
    if(top == bottom){
        for(int j =0;j<n;j++){
            if(mat[top][j] == 1){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(i!= top && mat[i][top] != 1){
                return -1;
            }
        }
        
    }
    return top;
}