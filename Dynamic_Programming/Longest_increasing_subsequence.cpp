#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n){
    int ls[n];

    ls[0] = 1;    
    for(int i = 1; i<n; i++){
        ls[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j] && ls[i] < 1 + ls[j])
                ls[i] = 1 + ls[j];
        }
    }

    return *max_element(ls , ls + n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    cout<<lis(arr, n);
    return 0;
}