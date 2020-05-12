#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    for(int i = 0; i<n1; i++)
        L[i] = arr[l + i];
    for(int i = 0; i<n2; i++)
        R[i] = arr[mid + 1 + i];
    int i , j,  k;
    i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i];
            i++;
        }
        else{
            arr[k++] = R[j];
            j++;
        }
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    mergeSort(arr, 0, n - 1);
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}