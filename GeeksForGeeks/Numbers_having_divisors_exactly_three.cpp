#include<bits/stdc++.h>
using namespace std;

// To find the number of no's whose divisors are exactly 3.
// Method is every number whose square root is prime then those have exactly 3 divisors. e.g = 4 , 9, 25 etc.
typedef long long ll;
bool isPrime(ll n){
    if(n == 0 || n == 1)
        return false;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

ll countDivisors(ll n){
    long long res = 0, x = 2;
    while(x * x <= n){
        if(isPrime(x) && x * x <= n)
            res++;
        x++;
    }
    return res;
}

int main(){
    ll n;
    cin>>n;
    ll res = countDivisors(n);
    cout<<res<<endl;
}