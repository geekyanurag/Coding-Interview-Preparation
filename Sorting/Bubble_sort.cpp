#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubblesort(int arr[], int n){
    for(int i =0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] < arr[j-1])
                swap(arr[j], arr[j-1]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    bubblesort(arr, n);

    for(int i : arr)
        cout<<i<<" ";
    return 0;
}