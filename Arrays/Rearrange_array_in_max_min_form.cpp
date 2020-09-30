#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Problem is given a sorted array and we have to arrange the array such a way that first number will be first max_number  and second will
// be first min_number and similarly arrange the whole array.
void rearrange(vector<ll>arr){
    ll n = arr.size();
    ll min_idx = 0, max_idx = n - 1;
    ll k = arr[n - 1] + 1;
    
    for(ll i = 0; i<n; i++){
        if(i % 2 == 0){
            arr[i] = (arr[max_idx] % k) * k + arr[i];
            max_idx--;
        }
        else{
            arr[i] = (arr[min_idx] % k) * k + arr[i];
            min_idx++;
        }
    }
        
    for(ll i = 0; i<n; i++)
        arr[i] = arr[i] / k;
    
    for(ll i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n);
        for(ll i = 0; i<n; i++)
            cin>>arr[i];
        rearrange(arr);
    }
    return 0;
}