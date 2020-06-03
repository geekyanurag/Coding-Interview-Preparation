#include<bits/stdc++.h>
using namespace std;

// Using dp takes O(n * n) time and O(n*n) space.
int lps(string s){
    int n = s.length(), res = 0;
    bool dp[n][n];

    for(int i =0; i<n; i++)
        dp[i][i] = 1;
    
    int j;
    for(int l = 2; l<=n; l++){
        for(int i = 0; i<=n-l; i++){
            j = i + l - 1;
            if(l == 2)
                dp[i][j] = (s[i] == s[j]);
            else 
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
            
            if(dp[i][j])
                res = max(res, l);
        }
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    cout<<lps(s);
    return 0;
}