#include<bits/stdc++.h>
using namespace std;

// Catalan numbers follow - T(n) = summationof(i to n-1)(T(i) * T(n-i-1)) where T(0) = 1 and n>=1
// It can also be found by - 2nCn / (n+1)
int catalan(int n){
    int ct[n+1];
    ct[0] = 1;
    for(int i =1; i<=n; i++){
        int res = 0;
        for(int j = 0; j<i; j++){
            res += ct[j] * ct[i - j - 1];
        }
        ct[i] = res;
    }
    return ct[n];
}
int main(){
    int n;
    cin>>n;
    cout<<catalan(n)<<endl;
}