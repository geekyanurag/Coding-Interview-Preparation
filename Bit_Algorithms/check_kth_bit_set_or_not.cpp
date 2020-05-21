#include<bits/stdc++.h>
using namespace std;

bool isSet(int n, int k){
    return (1 << k) & n;
}
int main(){
    int n, k;
    cin>>n>>k;
    cout<<isSet(n, k);
}