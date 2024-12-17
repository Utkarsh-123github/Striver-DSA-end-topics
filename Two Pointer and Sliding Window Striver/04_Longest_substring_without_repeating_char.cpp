//Given a string s, find the length of the longest substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

#include<bits/stdc++.h>
using namespace std;

// Generating all substrings and using hashing to check if the substring has repeating characters or not.
// TC : O(n^2)
// SC : O(256)

int lengthOfLongestSubstring(string s){
    int n = s.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
        vector<int>hash(256,0);
        for(int j=i;j<n;j++){
            if(hash[s[j]]==1){
                break;
            }
            maxLen = max(maxLen,j-i+1);
            hash[s[j]]++;
        }
    }
    return maxLen;
}

// Sliding window approach
// TC : O(n)
// SC : O(256)

int lengthOfLS(string s){
    int n = s.size();
    int maxLen = 0;
    vector<int>hash(256,-1);
    int l = 0;
    int r = 0;
    while(r<n){
        if(hash[s[r]]!=-1){
            l = max(l,hash[s[r]]+1);
        }
        hash[s[r]] = r;
        maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}

int main(){
    string s = "abcabcbb";
    cout<<lengthOfLS(s)<<endl;
    return 0;
}