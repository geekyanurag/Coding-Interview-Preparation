#include<bits/stdc++.h>
using namespace std;

// if a mixture of +ve and -ve integers are there in array than it finds the maximum sum in the array not necessarily contiguous.
int maxSum(int arr[], int n){
    int sum = 0, max_sum = INT_MIN;
    for(int i =0; i<n; i++){
        sum = max(sum, sum + arr[i]);
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    cout<<maxSum(arr, n);
}
