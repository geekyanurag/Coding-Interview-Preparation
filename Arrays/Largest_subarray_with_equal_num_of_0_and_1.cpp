#include<bits/stdc++.h>
using namespace std;

// The problem can be changed to largest subarray with sum 0 by changing the 0 to -1
// Then take the cumulative sum and check if sum present in hashmap if yes then subtract the index stored in hashmap
// with current index and if 0 is there then current index + 1 then update max_sum
int equal_subarray(int n){
    vector<int>v(n);
    for(int i =0; i<n; i++)
        cin>>v[i];
    for(int i =0; i<n; i++){
        if(v[i] == 0)
            v[i] = -1;
    }
    unordered_map<int,int>mp;
    int max_sum = 0, len = 0, sum = 0;
    for(int i =0; i<v.size(); i++){
        sum += v[i];
        if(sum == 0){
            len = i + 1;
            max_sum = max(max_sum, len);
        }
        else{
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
            else{
                max_sum = max(max_sum, i - mp[sum]);
            }
        }
    }
    return max_sum;
}
int main(){
    int n;
    cin>>n;
    int res = equal_subarray(n);
    cout<<res<<endl;
}