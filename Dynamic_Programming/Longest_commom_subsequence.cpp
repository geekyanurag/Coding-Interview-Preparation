#include<bits/stdc++.h>
using namespace std;

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