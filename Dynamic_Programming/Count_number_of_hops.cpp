#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Problem is to count the number of ways we can take to reach the nth step taking 1, 2 or 3 steps.
int solve(int n){
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;
    fib[3] = 4;
    for(int i = 4; i<=n; i++)
        fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3];
    return fib[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;  // For t number of test cases 
    cin>>t;
    while(t--){
        int n;  // n is the nth stair where we have to reach
        cin>>n;
        int res = solve(n);
        cout<<res<<endl;
    }
    return 0;
}