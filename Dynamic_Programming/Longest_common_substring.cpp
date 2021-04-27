#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Recursive approach
int lcs1(int i, int j, int count)
{
 
    if (i == 0 || j == 0)
        return count;
 
    if (X[i - 1] == Y[j - 1]) {
        count = lcs1(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs1(i, j - 1, 0),
                    lcs1(i - 1, j, 0)));
    return count;
}

// DP approach
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