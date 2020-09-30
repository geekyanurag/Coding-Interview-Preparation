#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll missing(vector<ll>arr){
    ll sum = 0, total = 0;
    ll n = arr.size();
    for(int i = 0 ; i<n; i++){
        sum += arr[i];
    }
    for(int i = 1; i<=n + 1; i++)
        total += i;
    ll miss_num = total - sum;
    return miss_num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n-1);
        for(int i = 0; i<n-1; i++)
            cin>>arr[i];
        ll res = missing(arr);
        cout<<res<<endl;
    }
    return 0;
}