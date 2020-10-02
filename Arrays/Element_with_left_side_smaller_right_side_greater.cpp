#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Find the first element such that all the elements towards its left is smaller than it and all elements after it is greater than it.
// Solution is take two array left , right. left will store the maximum till ith position ad right will store the minimum till jth position.
// So if maximum in left of curr element is smaller than curr element and minimum in right is greater than curr element then that is the number.
int solve(int arr[], int n){
    if(n == 1 || n == 2) return -1;
    
    int left[n], right[n], ans = 0;
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    for(int i =1; i<n; i++){
        if(arr[i] > left[i - 1])
            left[i] = arr[i];
        else left[i] = left[i-1];
    }
    
    for(int i = n - 2; i>=0; i--){
        if(arr[i] < right[i + 1])
            right[i] = arr[i];
        else right[i] = right[i + 1];
    }
    
    for(int i = 1; i<n - 1; i++){
        if(left[i - 1] <= arr[i] && right[i + 1] >= arr[i]){
            ans = arr[i];
            break;
        }
    }
    if(ans == 0) ans = -1;
    return ans;
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
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        
        int res = solve(arr, n);
        cout<<res<<endl;
    }
    return 0;
}