// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

#include<bits/stdc++.h>
using namespace std;

int fn(string s){
    int n = s.length();
    int cnt = 0;
    for(int i=0;i<n;i++){
        vector<int>hash(3,0);
        for(int j=i;j<n;j++){
            hash[s[j]-'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3){
                cnt++;
            }
        }
    }
    return cnt;
}

// Optimal approach : Using concept of minimum window 
// TC = O(n)
// SC = O(1)

int fn2(string s){
    int n = s.length();
    vector<int>lastSeen(3,-1);
    int cnt = 0;
    for(int i=0;i<n;i++){
        lastSeen[s[i]-'a'] = i;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            cnt =  cnt + 1 + min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        }
    }
    return cnt;
}

int main(){
    string s;
    cin>>s;
    cout<<fn2(s)<<endl;
    return 0;
}