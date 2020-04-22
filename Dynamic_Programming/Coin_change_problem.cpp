// Counting the number of ways to give change if we have infinite supply of coins
#include<bits/stdc++.h>
using namespace std;

// time is O(n*sum) and also with extra space
int change(int coins[], int n, int sum){
    int count[n+1][sum+1];
    //memset(count, 0, sizeof(count));
    for(int i =0; i<=n; i++)
        count[i][0] = 1;
    for(int i = 1; i<=sum; i++)
        count[0][i] = 0;
        
        
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(j < coins[i-1])
                count[i][j] = count[i-1][j];
            if(j >= coins[i-1])
                count[i][j] = count[i-1][j] + count[i][j-coins[i-1]];     //Similar to subset sum problem but only difference is count[i][j] = count[i-1][j] + count[i-1][j-coins[i-1]] in subset.
        }
    }
    return count[n][sum];
}

int main(){
    int n, k;
    cin>>n>>k;
    int coins[n];
    for(int i = 0; i<n; i++)
        cin>>coins[i];
    //cout<<change(coins, n, k);
    cout<<change1(coins, n, k);
}