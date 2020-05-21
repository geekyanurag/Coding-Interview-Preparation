#include<bits/stdc++.h>
using namespace std;

int isPower(int n){
    if((n & (n - 1)) == 0)
        return true;
    else 
        return false;
}
int main(){
    int n;
    cin>>n;
    cout<<isPower(n);
    return 0;
}