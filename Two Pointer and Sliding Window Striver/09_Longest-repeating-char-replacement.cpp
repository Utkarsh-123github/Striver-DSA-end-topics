#include<bits/stdc++.h>
using namespace std;

// TC = O(n)
// SC = O(distinct char)

int fn(string s, int k){
    int n = s.length(), l = 0, r = 0, maxLen = 0, maxFreq = 0;
    map<char,int>mpp;
    while(r<n){
        mpp[s[r]]++;
        maxFreq = max(maxFreq,mpp[s[r]]);
        if(r-l+1 - maxFreq > k){
            mpp[s[l]]--;
            l++;
        }
        if(r-l+1-maxFreq <= k){
            maxLen = max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main(){
    string s = "AABABBA";
    cout<<fn(s,1);
    return 0;
}