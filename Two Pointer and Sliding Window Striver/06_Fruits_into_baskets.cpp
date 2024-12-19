// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array of fruits, return the maximum number of fruits you can pick.

// Example 1:
// Input: arr = [1,2,1]
// Output: 3

// Example 2:
// Input: arr = [0,1,2,2]
// Output: 3

// This prblm can be considered as max length subarray with at most 2 distinct elements.


#include<bits/stdc++.h>
using namespace std;   

// brute approach 
int solve1(vector<int>&arr){
    int n = arr.size();
    int maxFruits = 0;
    for(int i=0;i<n;i++){
        set<int>st;
        int count = 0;
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if(st.size()<=2){
                maxFruits = max(maxFruits,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxFruits;
}

// TC = O(n^2)
// SC = O(1)

// Optimal approach using sliding window
int solve2(vector<int>&arr){
    int n = arr.size();
    int maxFruits = 0;
    unordered_map<int,int>mp;
    int l = 0;
    int r = 0;
    while(r<n){
        mp[arr[r]]++;
        if(mp.size() > 2){
            while(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
            }
        }

        if(mp.size()<=2){
            maxFruits = max(maxFruits,r-l+1);
        }
        r++;
    }
    return maxFruits;
}

// TC = O(2n)
// SC = O(1)

int main(){
    vector<int>arr = {1,2,1};
    cout<<solve2(arr)<<endl;
    return 0;
}