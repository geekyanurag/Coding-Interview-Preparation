#include<bits/stdc++.h>
using namespace std;

int mergeSort1(int arr[], int temp[], int low, int high);
int merge(int arr[], int temp[], int low, int mid, int high);

int mergeSort(int arr[], int n){
    int temp[n];
    return mergeSort1(arr, temp, 0, n-1);
}

int mergeSort1(int arr[], int temp[], int low, int high){
    int mid, ans = 0;

    if(low < high){
        mid = (low + high) >> 1;
        ans += mergeSort1(arr , temp, 0, mid);
        ans += mergeSort1(arr, temp, mid + 1, high);
        ans += merge(arr, temp, low, mid + 1, high);
    }
    return ans;
}

int merge(int arr[], int temp[], int low, int mid, int high){
    int ans = 0, i, j, k;
    i = low, j = mid, k = low;

    while((i < mid) && (j <= high)){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else{ 
            temp[k++] = arr[j++];
            ans += (mid - i);
        }
    }

    while(i < mid)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];
    
    for(int i = low; i<= high; i++)
        arr[i] = temp[i];
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    int res = mergeSort(arr, n);
    cout<<res<<endl;
    return 0;
}