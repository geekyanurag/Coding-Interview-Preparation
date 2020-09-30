#include<bits/stdc++.h>
#define ll long long
using namespace std;

int lcs(string a, string b, int m, int n){
    int dp[m+1][n+1], ans = 0;
    memset(dp, 0, sizeof(dp)); // set all the values of dp matrix to 0
    for(int i = 1; i<=m; i++){
        for(int j= 1; j<=n; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin>>a>>b;
    int m = a.length(), n = b.length();
    int res = lcs(a, b, m, n);
    cout<<res<<endl;
    return 0;
}