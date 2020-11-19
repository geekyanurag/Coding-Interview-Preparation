#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Given a sorted and rotated array (ie circular rotated array) and we find the key in the array.
// Using binary search to find the key.
int search(vector<int>arr, int key){
    int n = arr.size();
    if(n == 0) return -1;
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(arr[mid] == key) return mid;
        
        if(arr[mid] <= arr[r]){             // Checking if array from mid to r is sorted or not.
            if(key > arr[mid] && key <= arr[r])     // Checking if key lies in range (mid, r]. we are not including mid because we are checking if arr[mid] == key already.
                l = mid + 1;
            else r = mid - 1;
        }
        else{                               // If mid to r is not sorted then l to mid must be sorted.                           
            if(key >= arr[l] && key < arr[mid])     // Checking if key lies in range [l, mid) 
                r = mid - 1;
            else l = mid + 1;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;      // Taking multiple test cases.
    cin>>t;
    while(t--){
        int n, key;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0; i<n; i++) cin>>arr[i];
        cin>>key;
        int res = search(arr, key);
        cout<<res<<endl;
    }
    return 0;
}