#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll smallest(ll n){

    if(n >=0 && n <= 9)
        return n;

    stack<int>digits;
    ll num = 0;

    for(int i = 9; i >= 2 && n > 1; i--){
        while(n % i == 0){
            digits.push(i);
            n /= i;
        }
    }

    if(n != 1)
        return -1;
    
    while(!digits.empty()){
        num = (num * 10) + digits.top();
        digits.pop();
    }

    return num;
    
}
int main(){
    ll x;
    cin>>x;
    ll ans = smallest(x);
    cout<<ans<<endl;
}