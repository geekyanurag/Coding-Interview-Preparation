#include<bits/stdc++.h>
using namespace std;

// Given a set of elements in array we have to find all the sets of 4 integers whose sum is equal to k.
void fourSum(vector<int>arr, int k){
    sort(arr.begin(), arr.end());

    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        for(int j = i + 1; j<n; j++){
            int l = j + 1, r = n - 1;
            while(l < r){
                int sum = arr[i] + arr[j] + arr[l] + arr[r];
                if(sum == k){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                    l++, r--;
                }
                else if(sum > k) r--;
                else l++;
            }
        }
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    fourSum(arr, k);
    return 0;
}