#include<bits/stdc++.h>
using namespace std;

// Idea is to take a pivot element (can be firt or middle or last element) and partition the array around the pivot element.
// Partition is done in such a way that the elements on left of pivot are smaller than pivot and on right will be greater than pivot.
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high], j = low - 1;
    for(int i =low; i<high; i++){
        if(arr[i] < pivot){
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j+1], arr[high]);
    return j+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    quickSort(arr, 0, n-1);
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}