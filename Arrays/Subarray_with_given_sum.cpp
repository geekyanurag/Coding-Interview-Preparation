#include<bits/stdc++.h>
using namespace std;

// Unsorted array is given then find Subarray with sum = k for non-negative integers. It gives the subarray range indexing from 1.
void subSum(int arr[], int n, int sum){
    int curr_sum = arr[0], j = 0;
    for(int i = 1; i<=n; i++){
        while(curr_sum > sum && j < i - 1){
            curr_sum -= arr[j];
            j++;
        }
        if(curr_sum == sum){
            cout<<j + 1 << " "<< i<<endl;
            break;
        }
        if(i < n)
            curr_sum += arr[i];
    }
    if(curr_sum != sum)
        cout<<"-1"<<endl;
}

// For handling negative integers and is 0 based indexing.
// Using map for storing, if the curr_sum - sum is there in map then subarray found with sum k else map[curr_sum] = index;
void subSum1(int arr[], int n, int sum){
    int curr_sum = 0;
    unordered_map<int, int>mp;
    for(int i =0; i<n; i++){
        curr_sum += arr[i];
        if(curr_sum == sum){
            cout<<"0"<<" "<<i<<endl;
        }
        if(mp.find(curr_sum - sum) != mp.end()){
            cout<<mp[curr_sum - sum] + 1<<" "<<i<<endl;
        }
        mp[curr_sum] = i;
    }
}

int main(){
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    subSum(arr, n, sum);
    subSum1(arr, n, sum);
    return 0;
}