#include<bits/stdc++.h>
using namespace std;

// More optimized Solution, time - O(n),  space - O(1)
int permutation2(int n, int k){
    if(k > n) return 0;

    int p = 1; 

    for(int i = 0; i<k; i++)        // we have to calculate n * (n - 1) * (n - 2)......*(n - k + 1) because after (n - k + 1) it will be cancelled by the denominator ie (n - k)!
        p *= (n - i);
    
    return p;
}
// Efficient Solution , time - O(n), space - O(n)
int permutation1(int n, int k){
    if(k > n)
        return 0;

    int p[n + 1];
    p[0] = 1;

    for(int i = 1; i<=n; i++)
        p[i] = i * p[i - 1];
    
    return p[n] / p[n - k];     // So here p[n] = n! and p[n - k] = (n - k)!
}

// DP approach using the formula - P(n, k) = P(n - 1, k) + k * P(n - 1, k - 1).
// Time - O(n * k), Space - O(n * k)
int permutation(int n, int k){
    int p[n + 1][k + 1];
    
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=k; j++)
            p[i][j] = 0;
    }

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=min(i, k); j++){
            if(j == 0) p[i][j] = 1;
            else
                p[i][j] = p[i - 1][j] + (j * p[i - 1][j - 1]);
        }
    }

    return p[n][k];
}

int main(){
    int n, k;
    cin>>n>>k;
    cout<<permutation(n, k)<<endl;
    cout<<permutation1(n, k)<<endl;
    cout<<permutation2(n, k)<<endl;
    return 0;
}