#include<bits/stdc++.h>
using namespace std;

// Idea is to take the ith element as key and compare it with elements before it until the element before it will be smaller otherwise shift the elements forward.
// Similarly do it for rest of the array.
void swap(int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i], j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j+1] = key;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    insertionSort(arr, n);
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}