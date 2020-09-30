#include<bits/stdc++.h>
using namespace std;

int maxSumlis(int arr[], int n){
    int dp[n];
    for(int i = 0; i<n; i++)
        dp[i] = arr[i];
    
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];
        }
    }
    return *max_element(dp, dp + n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int res = maxSumlis(arr, n);
    cout<<res<<endl;
}