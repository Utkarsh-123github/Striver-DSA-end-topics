// Here we'll deal with constant window size
// For eg : arr = [-1,2,3,4,5,-1] , you can pick k=4 coonsecutive elements at a time and return max Sum
// So, the output will be 14 (2+3+4+5)

#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int>arr,int k){
    int l=0, r= k-1;
    int sum = 0;
    int maxSum = 0;
    int n = arr.size();
    if(r>=n){
        return -1;
    }

    for(int i=0;i<k;i++){
        sum+=arr[i];
    }

    maxSum = sum;

    while(r<n-1){
        sum = sum-arr[l];
        l++;
        r++;
        sum = sum+arr[r];
        maxSum = max(maxSum,sum);
    }

    return maxSum;
}

int main(){
    vector<int>arr = {-1,2,3,4,5,-1};
    int k = 4;
    cout<<maxSum(arr,k);
    return 0;
}