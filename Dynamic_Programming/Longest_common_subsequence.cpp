#include<bits/stdc++.h>
using namespace std;

//Recursive Approach
int lcs1( char *X, char *Y, int m, int n ) 
{ 
    if (m == 0 || n == 0) 
        return 0; 
    if (X[m-1] == Y[n-1]) 
        return 1 + lcs1(X, Y, m-1, n-1); 
    else
        return max(lcs1(X, Y, m, n-1), lcs1(X, Y, m-1, n)); 
} 

// DP Approach
int lcs(string a, string b){
    int m = a.length();
    int n = b.length();
    int lcs[m+1][n+1];
    //memset(lcs, 0, sizeof(lcs));

    for(int i =0; i<=m; i++){
        for(int j = 0 ; j<=n; j++){
            if(i == 0 || j == 0)
                lcs[i][j] = 0;

            else if(a[i-1] == b[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else 
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    return lcs[m][n];
}

int main(){
    string a, b;
    cin>>a>>b;
    cout<<lcs(a, b);
    return 0;
}