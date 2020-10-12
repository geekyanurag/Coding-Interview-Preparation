#include<bits/stdc++.h>
using namespace std;

// Finding the number of subarrays whose sum is divisible by k.
// sum(arr[i...j]) % k == 0  => [ sum(arr[0.....j]) - sum(arr[0......i]) ]% k = 0  => sum(arr[0....j]) % k = sum(arr[0....i]) % k.
// So the remainder of curr_sum with k already exists in the map then obviously the count of remainder will be greater than 1. So we are taking nc2 combinations.
int count_subarrays(vector<int>arr, int k){
    int n = arr.size();
    int sum = 0, count = 0;
    unordered_map<int,int>mp;

    for(int i =0; i<n; i++){
        sum += arr[i];
        mp[((sum % k) + k) % k]++;      // Storing the remainder of the cumulative sum with k. As the sum can be negative so add k to sum then take modulo k.
    }

    for(int i = 0; i<k; i++){
        if(mp[i] > 1)                   // The remainder always lie b/w 0 to k - 1. So taking all the remainder which are greater than 1 only that because we can take (nc2) pairs.
            count += (mp[i] * (mp[i] - 1)) / 2;
    }

    count += mp[0];

    return count;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int res = count_subarrays(arr, k);
    cout<<res<<endl;
}