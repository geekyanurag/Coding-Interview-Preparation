#include<bits/stdc++.h>
using namespace std;

/* The problem is to maximize the number of zeroes by flipping the subarray 
  e.g = arr = {0, 1, 0, 0, 1, 1, 0} so the subarray {1, 1} is flipped to {0, 0} so the number of zeroes will be 6.
  The idea is to apply kadane algo to find the max subarray sum by converting 0 to -1 and calculate the sum . If max sum will be -ve then
  it will be 0 otherwise max sum and return the max sum + number of zeroes. */
int maxZeroes(int arr[], int n){
    int max_sum = 0, num_zeroes = 0, curr_sum = 0;

    for(int i =0; i<n; i++){
        if(arr[i] == 0)
            num_zeroes++;
        int val = (arr[i] == 1) ? 1 : -1;
        curr_sum = max(val, curr_sum + val);
        max_sum = max(curr_sum, max_sum);
    }
    max_sum = max(0, max_sum);
    return max_sum + num_zeroes;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    int res = maxZeroes(arr, n);
    cout<<res<<endl;
    return 0;
}