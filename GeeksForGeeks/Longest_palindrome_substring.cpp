// Problem is to find the longest palindromic substring and return that substring.
string longestPalindrome(string A) {
    int n = A.length(), res = 1, start = 0, end = 0;
    bool dp[n][n];
    string s;
    int j;
    for(int i = 0; i<n; i++)
        dp[i][i] = true;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i<= n-l; i++){
            j = i + l - 1;
            if(l == 2)
                dp[i][j] = (A[i] == A[j]);
            else
                dp[i][j] = (A[i] == A[j]) && dp[i+1][j-1];
            if(l > res && dp[i][j]){
                res = l;
                start = i;
                end = j;
            }
        }
    }
    if(res == 1)
        s += A[0];
    else {
    for(int i = start; i<= end; i++)
        s += A[i];
    }
    return s;
}