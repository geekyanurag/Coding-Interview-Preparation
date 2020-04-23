#include<bits/stdc++.h>
using namespace std;

// This algorithm is also known as Kadane's algorithm
// This case is not for all -ve in array
int maxSum(int arr[], int n){
    int sum = 0, max_sum = INT_MIN;
    for(int i =0; i<n; i++){
        sum += arr[i];
        if(max_sum < sum)
            max_sum = sum;
        if(sum < 0)
            sum = 0;
    }
    return max_sum;
}

// Case when all -ve is also there
int maxSum1(int arr[], int n){
    int sum = arr[0], max_sum = arr[0];
    for(int i =1; i<n; i++){
        sum = max(arr[i], sum + arr[i]);
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0 ; i<n; i++)
        cin>>arr[i];
    //cout<<maxSum(arr, n)<<endl;
    cout<<maxSum1(arr, n)<<endl;
}