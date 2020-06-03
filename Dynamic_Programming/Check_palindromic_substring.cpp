#include<bits/stdc++.h>
using namespace std;

// check whether the substring s[i..j] from i to j is palindrome or not.
bool isPalindrome(string s, int x, int y){
    int n = s.length();
    bool dp[n][n];
    for(int i =0; i<n; i++)
        dp[i][i] = true;

    int j ;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i <= n-l; i++){
            j = i + l - 1;
            if(l == 2)
                dp[i][j] = (s[i] == s[j]);
            else 
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
        }
    }
    return dp[x][y];
}
int main(){
    string s;
    cin>>s;
    int start, end;
    cin>>start>>end;
    cout<<isPalindrome(s, start, end);
    return 0;
}