#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(int a, int b){
    if(b == 0)
        return a;
    else return gcd(b, a % b);
}

// Finding lcm for array elements
ll lcm(int arr[], int n){
    int res = arr[0];

    for(int i = 1; i<n; i++){
        res = (res * arr[i]) / gcd(arr[i], res);
    }

    return res;
}

// Finding gcd of array elements
ll gcd(int arr[], int n){
    int res = arr[0];

    for(int i = 1; i<n; i++){
        res = gcd(res, arr[i]);
        if(res == 1)
            return 1;
    }
    
    return res;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    ll res = lcm(arr, n);
    ll res2 = gcd(arr, n);
    cout<<res<<" "<<res2<<endl;
    return 0;
}