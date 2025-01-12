// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Approach : We'll try to place smaller digits at the beginning(i.e leftmost beginning)
// Edge cases : 
// 1. K should be less than equal to n
// 2. if output contains leading zeros , we have to remove it
// 3. If input is sorted , just remove k digits from the end (i.e rightmost end)

// TC = O(n)
// SC = O(n)

#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k){
    int n = num.length();
    if(k>=n)return "0";
    stack<char>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()-'0' > num[i]-'0'){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    // Remove leading zeros if any
    while(ans.length() != 0 && ans.back() == '0'){
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string num = "1432219";
    string num2 = "10000001";
    cout<<removeKdigits(num2,1)<<endl;
    cout<<removeKdigits(num,3)<<endl;
    return 0;
}
