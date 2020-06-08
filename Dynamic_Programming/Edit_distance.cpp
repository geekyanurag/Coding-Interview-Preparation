#include<bits/stdc++.h>
using namespace std;

// In this approach space complexity will be more.
int editDistance(string a, string b){
    int m = a.length();
    int n = b.length();

    int dp[m+1][n+1];

    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=n; j++){
            if(i == 0)
                dp[i][j] = j;

            else if(j == 0)
                dp[i][j] = i;
            
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            
            else 
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }

    return dp[m][n];
}

// Space optimized Solution

int editDistance1(string a, string b){
    int m = a.length();
    int n = b.length();

    int dp[2][m+1];

    for(int i = 0; i<2; i++)
        for(int j = 0; j<m; j++)
            dp[i][j] = 0;

    for(int i  = 0; i<=m; i++)
        dp[0][i] = i;

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(j == 0)
                dp[i % 2][j] = i;
            
            else if(a[j-1] == b[i-1])
                dp[i % 2][j] = dp[(i - 1) % 2][j-1];
            
            else 
                dp[i % 2][j] = 1 + min({dp[(i - 1) % 2][j], dp[i % 2][j-1], dp[(i - 1) % 2][j-1]});
        }
    }
    return dp[n % 2][m];
}

int main(){
    string a, b;
    cin>>a>>b;
    cout<<editDistance(a, b)<<endl;
    cout<<editDistance1(a, b)<<endl;
    return 0;
}