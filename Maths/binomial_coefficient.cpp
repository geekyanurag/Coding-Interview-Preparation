#include<bits/stdc++.h>
using namespace std;

// DP approach with space optimized one
// Time - O(n *k), Space - O(k)
int binomial1(int n, int k){
    int c[k + 1];
    //memset(c, 0, sizeof(c));
    for(int i = 0; i<=k; i++)
        c[i] = 0;
    c[0] = 1;

    for(int i = 1; i<=n; i++){
        for(int j = min(i, k); j > 0; j--){
            c[j] = c[j - 1] + c[j];
        }
    }

    return c[k];
}

// DP Approach and efficient one 
// Time complexity - O(n * k), Space Complexity - O(n * k)
int binomial(int n, int k){
    int c[n + 1][k + 1];

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=k; j++)
            c[i][j] = 0;
    }
    
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=min(i, k); j++){
            if(j == 0 || j == i) c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    return c[n][k];
}

// Basic Approach
int binomialCoeff(int n, int k){
    if(k > n) return 0;
    int res = 1;
    if(k > n - k)
        k = n - k;
    for(int i =0; i<k; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int main(){
    int n, k;
    cin>>n>>k;
    cout<<binomialCoeff(n, k)<<endl;
    cout<<binomial(n, k)<<endl;
    cout<<binomial1(n, k)<<endl;
}