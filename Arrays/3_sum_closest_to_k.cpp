#include<bits/stdc++.h>
using namespace std;

// Given a set of integer print all the set of 3 integers whose sum is closest to a given number k.
int threeSumClosest(vector<int>arr, int k){
    sort(arr.begin(), arr.end());

    int n = arr.size(), diff = INT_MAX, ans;

    for(int i = 0; i<n; i++){
        int l = i + 1, r = n-1;
        while(l < r){
            int sum = arr[i] + arr[l] + arr[r];
            if(abs(k - sum) < abs(diff)){
                diff = k - sum;
                ans = sum;
            }
            else if(sum > k) r--;
            else l++;
        }
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0; i<n ; i++)
        cin>>arr[i];
    int res = threeSumClosest(arr, k);
    cout<<res<<endl;
    return 0;
}