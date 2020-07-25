#include<bits/stdc++.h>
using namespace std;

// Given a set of integers print all the set of 3 integers whose sum is equal to 0.
void threeSum(vector<int>arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i = 0; i<n; i++){
        int l = i + 1, r = n-1;
        while(l < r){
            int sum = arr[i] + arr[l] + arr[r];
            if(sum == 0){
                cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                l++, r--;
            }
            else if(sum < 0)
                l++;
            else 
                r--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    threeSum(arr);
    return 0;
}