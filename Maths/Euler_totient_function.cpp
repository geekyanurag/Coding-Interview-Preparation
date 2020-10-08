#include<bits/stdc++.h>
using namespace std;

// This function gives the count of all the numbers from 1 to that number ie n which are coprime with n ie gcd(x, n) == 1
// Time complexity - O(sqrt(n))
int totient(int n){
    int res = n;

    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            res -= res / i;
        }
    }

    if(n > 1) res -= res / n;
    return res;
}

// Optimized one using sieve. Tiime complexity - O(n log (log n))

void totient1(int n){
    vector<int>phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;

    for(int i = 2; i<n; i++)
        phi[i] = i;

    for(int i = 2; i*i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j<n; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int res = totient(n);
    cout<<res<<endl;
    return 0;
}