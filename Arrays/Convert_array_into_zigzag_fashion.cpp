#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void zigZag(int arr[], int n){
    bool flag = true;

    for(int i =0; i<n - 1; i++){
        if(flag){
            if(arr[i] > arr[i + 1])
                swap(arr[i], arr[i+1]);
        }
        else{
            if(arr[i+1] > arr[i])
                swap(arr[i+1], arr[i]);
        }
        flag = !flag;
    }

    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    zigZag(arr, n);
    return 0;
}