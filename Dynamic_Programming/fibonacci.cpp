#include<bits/stdc++.h>
#define ll long long
using namespace std;

// O(n) time complexity and O(n) space complexity
int fib(int n){
    int fb[n + 1];
    fb[0] = 0;
    fb[1] = 1;
    for(int i = 2; i<=n; i++)
        fb[i] = fb[i-1] + fb[i-2];
    return fb[n];
}

//Another approach O(n) time complexity and O(1) space complexity
int fib1(int n){
    int a = 0, b = 1, c;
    for(int i =2; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
// Another Approach O(1) time and space complexity
int fib2(ll n){
    double x = (sqrt(5) + 1) / 2;
    return round(pow(x, n) / sqrt(5));
}
int main(){
    ll n;
    cin>>n;
    cout<<fib1(n)<<endl;
}

