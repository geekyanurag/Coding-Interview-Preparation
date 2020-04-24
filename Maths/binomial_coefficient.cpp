#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k){
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
}