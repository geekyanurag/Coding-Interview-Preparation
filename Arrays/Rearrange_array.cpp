// Problem is to rearrange an array which contains no. from 0 to size of array -1 , in such a way that arr[i] = arr[arr[i]] in constant space.
#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n){
    for(int i =0; i<n; i++)
        arr[i] += (arr[arr[i]] % n) * n;
    
    for(int i =0; i<n; i++)
        arr[i] /= n;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    rearrange(arr, n);
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}