#include<bits/stdc++.h>
using namespace std;

void printSubarray(int arr[], int n){
    int sum = 0;
    unordered_map<int, vector<int>>mp;
    vector<pair<int,int>>res;
    for(int i =0; i<n; i++){
        sum += arr[i];
        if(sum == 0)
            res.push_back({0, i});
        if(mp.find(sum) != mp.end()){
            vector<int>v = mp[sum];
            for(int j : v)
                res.push_back({j+1, i});
        }
        mp[sum].push_back(i);
    }
    cout<<"The number of subarrays with sum 0 is "<<res.size()<<endl;
    cout<<"The subarrays with sum 0 are "<<endl;
    for(pair<int,int> i : res)
        cout<<i.first<<" "<<i.second<<endl;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    printSubarray(arr, n);
    return 0;
}