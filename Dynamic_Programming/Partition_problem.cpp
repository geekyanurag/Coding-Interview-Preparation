// Given an array of elements check whether it can be divided into two subsets such that sum of each subset is same.

#include<bits/stdc++.h>
using namespace std;

bool isSubSum(int arr[], int n){
    int sum = 0;
    for(int i =0; i<n; i++)      // if sum is odd then we cannot divide into two subsets with sum = sum / 2.
        sum += arr[i];

    if(sum & 1)
        return false;
    
    bool dp[sum /2 + 1][n + 1];
    for(int i = 0; i<=n; i++)
        dp[0][i] = true;
    
    for(int i = 1; i<= sum / 2; i++)
        dp[i][0] = false;

    for(int i = 1; i<=sum /2; i++){
        for(int j = 1; j<=n; j++){
            dp[i][j] = dp[i][j-1];  // if the first element is greater than sum.
            if(i >= arr[j-1])       // if first element is less than or equal to sum.
                dp[i][j] = dp[i][j-1] || dp[i-arr[j-1]][j-1];
        }
    }
    return dp[sum / 2][n];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    cout<<isSubSum(arr, n)<<endl;
    return 0;
}