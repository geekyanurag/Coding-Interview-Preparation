#include<bits/stdc++.h>
using namespace std;

// The problem states that you have to merge the given two strings in such a way that the merged string which contain both the strings as subsequence and is the shortest string.
// The solution is we first find the longest common subsequence then subtract it from the length of both the strings as the longest string will be formed after we merged the whole string of a and b.
int scs(string a, string b){
    int m = a.length();
    int n = b.length();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
        }
    }
    return (m + n) - dp[m][n];
}

int main(){
    string a, b;
    cin>>a>>b;
    int res = scs(a, b);
    cout<<res<<endl;
}