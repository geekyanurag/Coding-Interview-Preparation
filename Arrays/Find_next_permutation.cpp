#include<bits/stdc++.h>
using namespace std;

// We have given a set of integers and we have to find the lexicographically next greater permutation of the given set of integers.
// e.g. -  given arr[] = {1, 2, 3}, then the ans is {1, 3, 2}
// The idea is to run a loop from right checking the current element is greater than next element till the current element is less than the next element.
// Then swap the current element with element just greater than that element and then reverse the element from next of current element till the last element.
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(int arr[], int l, int r){
    while(l <= r){
        swap(arr, l, r);
        l++, r--;
    }
}

bool nextPermutation(int arr[], int n){
    int i = n - 2;
    while(i >= 0 && arr[i] >= arr[i + 1]) i--;

    if(i < 0){
        reverse(arr, i + 1, n - 1);
    }
    else{
    int j = i + 1;
    while(arr[i] < arr[j] && j < n) j++;
    swap(arr, i, j-1);
    reverse(arr, i + 1, n - 1);
    return true;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    if(nextPermutation(arr, n)){
        for(int i = 0; i<n; i++)
            cout<<arr[i]<<" ";
    }
    else{
        cout<<"Not possible"<<endl;
        for(int i = 0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}