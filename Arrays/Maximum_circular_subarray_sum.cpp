#include<bits/stdc++.h>
using namespace std;

// Finding the maximum circular subarray sum. e.g = Input: a[] = {8, -8, 9, -9, 10, -11, 12}, Output: 22 (12 + 8 - 8 + 9 - 9 + 10).
// Idea is to first find the kadane sum for maximum subarray sum then find the original sum of array then change the sign of array elements
// and then calculate the maximum subarray sum then add this sum to the sum of all the array elements. Then compare this sum to the first kadane sum and return the largest sum.
int kadaneSum(int arr[], int n){
    int max_sum = INT_MIN, sum = 0;
    for(int i = 0; i<n ; i++){
        sum = max(arr[i], sum + arr[i]);
        max_sum = max(sum , max_sum);
    }
    return max_sum;
}

int solve(int arr[], int n){
    int maxn = kadaneSum(arr, n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        arr[i] = -arr[i];
    }
    int x = kadaneSum(arr, n);
    sum += x;
    return (maxn > sum) ? maxn : sum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int res = solve(arr, n);
    cout<<res<<endl;
    return 0;
}