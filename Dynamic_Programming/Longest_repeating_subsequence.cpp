#include<bits/stdc++.h>
#define ll long long
using namespace std;

// The idea is the longest repeating subsequence will be the longest common subsequence between the same string but only difference is the string should not match at same index ie i != j.
int lrs(string s){
    int n = s.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(s[i - 1] == s[j - 1] && i != j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main(){
    string s;
    cin>>s;
    int res = lrs(s);
    cout<<res<<endl;
}