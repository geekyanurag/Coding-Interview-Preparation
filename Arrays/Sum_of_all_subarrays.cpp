#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void sumSubarrays(int arr[], int n){
    ll sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i] * (i + 1) * (n - i);
    }
    cout<<sum<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    sumSubarrays(arr, n);
    return 0;
}