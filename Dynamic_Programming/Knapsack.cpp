#include<bits/stdc++.h>
using namespace std;

// This is bounded knapsack, also called as 0 / 1 knapsack because we have only 2 choices either take the item or do not take it.
// In this problem we have to maximize the value in the knapsack such that the weight of the knapsack doesn't exceed given weight.
int knapsack(int val[], int wt[], int W, int n){
    int dp[n + 1][W + 1];
    //memset(dp, 0, sizeof(dp));
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=W; j++)
            dp[i][j] = 0;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=W; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main(){
    int n, W;
    cin>>n>>W;
    int val[n], wt[n];
    for(int i = 0; i<n; i++)
        cin>>val[i];
    for(int j = 0; j<n; j++)
        cin>>wt[j];
    int res = knapsack(val, wt, W, n);
    cout<<res<<endl;
}