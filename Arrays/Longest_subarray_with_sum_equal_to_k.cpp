#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Finding the longest subarray having sum = k.
// For finding it we have to use map.
int solve(vector<int>arr, int k){
    int n = arr.size();
    int len = 0, max_len = 0;
    unordered_map<int,int>mp;
    int x = 0;
    for(int i = 0; i<n; i++){
        x += arr[i];
        if(x == k) max_len = i + 1;     // If subarray starts with index 0.
        
        if(mp.find(x) == mp.end())      // If sum is not there in map then insert the index of the cumulative sum.
            mp[x] = i;
            
        if(mp.find(x - k) != mp.end()){     // Else check if (sum - k) is present in the array or not.
            len = i - mp[x - k];
            max_len = max(len, max_len);
        }
    }
    return max_len;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        int res = solve(arr, k);
        cout<<res<<endl;
    }
    return 0;
}