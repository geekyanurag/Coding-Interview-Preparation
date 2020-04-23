#include<bits/stdc++.h>
using namespace std;

// Given array of integers find indices of 2 numbers whose sums up to the given target sum.
// we first find the difference of given sum and current num then if that num is there in map then return indices else store the current element in map.
// Time - O(n)
void twoSum(int arr[], int n, int sum){
    unordered_map<int,int>mp;
    for(int i =0 ; i<n ;i++){
        int x = sum - arr[i];
        if(mp.find(x) != mp.end()){
            cout<<mp[x]<<" "<<i;
            break;
        }
        mp[arr[i]] = i;
    }
}

int main(){
    int n, sum;
    cin>>n>>sum;
    int *arr = new int[n];
    for(int i =0; i<n ;i++)
        cin>>arr[i];
    twoSum(arr, n, sum);
}