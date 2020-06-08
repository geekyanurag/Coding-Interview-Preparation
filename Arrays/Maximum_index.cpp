#include<bits/stdc++.h>
using namespace std;

/* Given arr of integers, we have to maximize j - i where arr[j] > arr[i] .
So the idea is to take 2 arrays one calculate the latest min from left to right and one calculate the max from right to left, 
then take max_diff.
*/

int maxIndex(int arr[], int n){
    int left[n], right[n];
    left[0] = arr[0];
    for(int i =1; i<n; i++){
        left[i] = min(arr[i], left[i-1]);
    }
    
    right[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--){
        right[i] = max(arr[i], right[i+1]);
    }

    int max_diff = -1, i = 0, j = 0;

    while(i < n && j < n){
        if(left[i] < right[j]){
            max_diff = max(max_diff, j - i);
            j++;
        }
        else i++;
    }

    return max_diff;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    cout<<maxIndex(arr, n);
}