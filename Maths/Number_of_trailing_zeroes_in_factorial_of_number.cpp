#include<bits/stdc++.h>
#define ll long long
using namespace std;

int five(int n){
    int count = 0;
    for(int i =5; n / i >= 1; i *= 5){
        count += n / i;
    }
    return count;
}
int main(){
     int t;
     cin>>t;
     for(int i =0; i<t; i++){
         ll n;
         cin>>n;
         cout<<five(n)<<endl;
     }
}