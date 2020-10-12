#include<bits/stdc++.h>
using namespace std;

// Find the number of subarrays whose sum is equal to k.
// The idea is to store the cumulative sum - given_sum if it appears than the number of subarrays will be equal to the number of times curr_sum - given_sum appears before the curr_sum.
int count_subarrays(vector<int>arr, int given_sum){
    int n = arr.size();
    unordered_map<int,int>mp;
    int curr_sum = 0, count = 0;
    for(int i = 0; i<n; i++){
        curr_sum += arr[i];

        if(curr_sum == given_sum)       // Subarray which starts from index 0 and have sum = k.
            count++;
        
        if(mp.find(curr_sum - given_sum) != mp.end())       // If (curr_sum - given_sum) appears before than add that value to count.
            count += mp[curr_sum - given_sum];
        
        mp[curr_sum]++;
    }

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