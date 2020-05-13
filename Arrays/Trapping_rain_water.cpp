#include<bits/stdc++.h>
using namespace std;

// Problem is to count the units of water being trapped in the bars of variable size like arr = {2, 0, 1, 0, 4}. Here values are heights of the bars.
// The solution is to find the maximum in left side and the right side for each array element and then take the minimum of left and right and subtract the current element.

// Time complexity - O(n*n), Space complexity - O(1)
int waterCount(int arr[], int n){
    int res = 0;
    for(int i = 0; i<n; i++){
        int left_max = arr[i], right_max = arr[i];
        for(int j = 0; j < i; j++)
            left_max = max(arr[j], left_max);
        for(int j = i + 1; j < n; j++)
            right_max = max(arr[j], right_max);
        res += min(left_max, right_max) - arr[i];
    }
    return res;
}

// For reducing time complexity we precompute maximum element in left and right for each element.
// Time complexity - O(n), Space complexity - O(n)
int waterCount1(int arr[], int n){
    int left[n], right[n], res = 0;
    left[0] = arr[0];
    for(int i = 1; i<n; i++)
        left[i] = max(left[i-1], arr[i]);

    right[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--)
        right[i] = max(right[i+1], arr[i]);
    
    for(int i = 0; i<n; i++)
        res += min(left[i], right[i]) - arr[i];
    
    return res;
}

// Time Complexity - O(n), Space Complexity - O(1)
int waterCount2(int arr[], int n){
    int low = 0, high = n-1, left_max = 0, right_max = 0, res = 0;
    while(low <= high){
        if(arr[low] < arr[high]){
            if(arr[low] > left_max)
                left_max = arr[low];
            else
                res += left_max - arr[low];
            low++;
        }
        else{
            if(arr[high] > right_max)
                right_max = arr[high];
            else
                res += right_max - arr[high];
            high--;
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    int res = waterCount(arr, n);
    int res1 = waterCount1(arr, n);
    int res2 = waterCount2(arr, n);
    cout<<res<<" "<<res1<<" "<<res2<<endl;
}