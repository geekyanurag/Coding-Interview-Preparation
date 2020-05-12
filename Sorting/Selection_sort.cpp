#include<bits/stdc++.h>
using namespace std;

// Idea is to take the first element as min and find the element after min which is smaller than min and then swap it and similarly 
// do the following for rest of the array.
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n){
    for(int i =0; i<n; i++){
        int minm = i;
        for(int j = i+1; j<n; j++){
            if(arr[minm] > arr[j])
                minm = j;
        }
        swap(arr[i], arr[minm]);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    selectionSort(arr, n);
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}