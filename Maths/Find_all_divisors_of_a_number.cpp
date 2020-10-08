#include<bits/stdc++.h>
using namespace std;

// Finding all divisors or factors of a number. 
// All the divisors appear in a pair for example if n = 100, then the various pairs of divisors are: (1,100), (2,50), (4,25), (5,20), (10,10).
void divisors(int n){
    for(int i = 1; i*i <= n; i++){          // Till sqrt(n) 
        if(n % i == 0){
            if(n/i == i) cout<<i<<" ";      // if n/i is same as i then print it once.
            else{
                cout<<i<<" ";
                cout<<n/i<<" ";
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    divisors(n);
    return 0;
}