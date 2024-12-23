// You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

// For example:
// You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.


#include<bits/stdc++.h>
using namespace std;

int longest(string s, int k){
    int n = s.size();
    int maxlen = 0;
    unordered_map<char,int>mp;
    int l = 0;
    int r = 0;
    while(r<n){
        mp[s[r]]++;
        if(mp.size() > k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
        }
        if(mp.size()<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int main(){
    string s = "abbbbbbc";
    int k = 2;
    cout<<longest(s,k)<<endl;
    return 0;
}