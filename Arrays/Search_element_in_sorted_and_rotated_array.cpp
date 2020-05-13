#include<bits/stdc++.h>
using namespace std;

// This implementation finds the pivot index in another function and then do the binary search on left of pivot or right of pivot.
int binarySearch(int arr[], int l, int h, int key){
    while(l <= h){
        int mid = (l + h) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            l = mid + 1;
        else 
            h = mid - 1;
    }
    return -1;
}

int findPivot(int arr[], int l, int h){
    if(l > h)  return -1;
    if(l == h) return l;

    int mid = (l + h) / 2;
    if(mid < h && arr[mid] > arr[mid + 1])
        return mid;
    if(mid > l && arr[mid] < arr[mid-1])
        return mid - 1;
    if(arr[l] >= arr[mid])
        return findPivot(arr, l, mid - 1);
    return findPivot(arr, mid + 1, h);
}

int pivotBinarySearch(int arr[], int n, int key){
    int pivot = findPivot(arr, 0, n-1);
    if(pivot == -1)
        return binarySearch(arr, 0, n-1, key);
    
    if(arr[pivot] == key)
        return pivot;
    if(arr[0] <= key)
        return binarySearch(arr, 0, pivot-1, key);
    return binarySearch(arr, pivot + 1, n - 1, key);
    
}

// Implemention in which finding pivot in same function.
int binarySearch1(int arr[], int l, int h, int key){
    if(l > h) return -1;
    int mid = (l + h) / 2;
    if(arr[mid] == key) return mid;
    if(arr[l] <= arr[mid]){         // Checking if low to mid subarray is sorted or not.
        if(key >= arr[l] && key <= arr[mid])
            return binarySearch1(arr, l, mid -1, key);
        return binarySearch1(arr, mid + 1, h, key);
    }
    
    if(key >= arr[mid] && key <= arr[h])    // If low to mid subarray is not sorted then mid to high must be sorted.
        return binarySearch1(arr, mid + 1, h, key);
    return binarySearch1(arr, l, mid - 1, key);
}

int main(){
    int arr[] = {3, 5, 6, 8, 9, 1, 2};
    int key = 1;
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = pivotBinarySearch(arr, n, key);
    int res1 = binarySearch1(arr, 0, n-1, key);
    cout<<res<<" "<<res1<<endl;
}