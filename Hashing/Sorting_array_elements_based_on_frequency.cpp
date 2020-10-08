#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Sorting of elements of array by frequency and if two no.'s having same frequency then print the smaller element first.
// Used Hashing to store the freq count and then sort the hash using vector then print it.
bool compare(pair<int,int>a, pair<int,int>b){
    if(a.second == b.second)
        return a < b;
    return a.second > b.second;
}
void sorting(map<int,int>mp){
    vector<pair<int,int>>v;
    for(auto i : mp)
        v.push_back(i);
    
    sort(v.begin(), v.end(), compare);
    
    for(auto i : v){
        for(int j = 0; j < i.second; j++)
            cout<<i.first<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        map<int,int>mp;
        for(int i = 0; i<n; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        sorting(mp);
    }
    return 0;
}