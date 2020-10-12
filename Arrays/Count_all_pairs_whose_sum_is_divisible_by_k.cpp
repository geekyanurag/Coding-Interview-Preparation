#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Find the count of all the pairs whose sum is divisible by k
ll count_pairs(vector<int>arr, int k){
    int n = arr.size();
    unordered_map<int,int>mp;
    for(int i = 0; i<n; i++)        // Store all the possible remainder values with k.
        mp[arr[i] % k]++;
    
    ll sum = (mp[0] * (mp[0] - 1)) / 2;     // If the remainder is 0 then all the numbers having remainder 0 is there in map. So there can be nC2 combinations of pairs so (nC2 = n * (n - 1) / 2)
    
    for(int i = 1; i <= (k/2) && i != k - i; i++){
        sum += (mp[i] * mp[k - i]);                 // We have to take the values in the pairs whose sum of remainder is equal to k. So taking all the values.
    }
    
    if(k % 2 == 0){
        sum += (mp[k / 2] * (mp[k / 2] - 1)) / 2;       // If k is even then take all the pairs whose remainder is k / 2.
    }
    
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        ll res = count_pairs(arr, 4);       // Taking k as 4
        cout<<res<<endl;
    }
    return 0;
}