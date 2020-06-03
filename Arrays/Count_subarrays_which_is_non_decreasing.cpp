#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// Given an array of number we have to count the number of subarrays which is non decreasing ie. increasing.
// The number of subarrays with n elements is equal to n * (n + 1) / 2 . ex = 1, 2, 3 = 3 * 4 >> 1 = 6 subarrays.
// Once a number which is lesser than the previous number is encountered we know that no subarray will be formed after that. 
// So total of from len = 1 to the current element , the total no. of subarrays will be counted then len will be 1 and check after that.
int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int n;
        cin>>n;
        vector<ll>v(n);
        ll count = 0, len = 1;
        for(int i =0; i<n; i++)
            cin>>v[i];

        for(int i = 0; i<n-1; i++){
            if(v[i+1] < v[i]){
                count += (len * (len + 1)) >> 1;
                len = 1;
            }
            else len++;
        }
        if(len >= 1) count += (len * (len + 1)) >> 1;
        cout<<count<<endl;
    }
}


// type - 2 is find the no. of subarrays which is non - increasing .

int nonIncreasing(vector<int>arr, int n){
    int count = 0, len = 1;
    for(int i =0; i<n-1; i++){
        if(arr[i+1] >= arr[i])
            len++;
        else{
            count += (len * (len + 1)) >> 1;
            len = 1;
        }
    }
    if(len > 1) count += (len * (len - 1)) >> 1;

    return count;
}