// Given an array of integers and we have to divide the array into 2 subsets such that abs(sum(set1) - sum(set2)) is minimum.
// Extension of partition problem.

#include<bits/stdc++.h>
using namespace std;

int minAbsDiff(int arr[], int n){
    int sum = 0;
    for(int i =0; i<n; i++)
        sum += arr[i];
    
    bool dp[n+1][sum+1];
    for(int i =0; i<=n; i++)
        dp[i][0] = true;
    
    for(int i = 1; i<=sum; i++)
        dp[0][i] = false;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= arr[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }

    int minDiff = INT_MAX;
    // Since we have to find the abs difference so if we have a set with sum j so sum of other set is (sum - j) so diff = (sum - j - j).
    // Since the minimum abs difference will be 0 so the diff will be 0 if one set will have a set of sum = sum / 2.
    for(int i = sum / 2; i>=0; i--){
        if(dp[n][i]){
            minDiff = sum - (2 * i);
            break;
        }
    }
    return minDiff;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    cout<<minAbsDiff(arr, n)<<endl;
    return 0;
}
