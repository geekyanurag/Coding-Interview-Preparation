#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Find number of all subarrays whose absolute sum is greater than k.
int countSubarrays(vector<int>arr, int k){
    int n = arr.size();
    int count = 0;

    for(int i = 1; i<n; i++){
        arr[i] += arr[i - 1];       // Taking prefix sum and storing in the array elements itself.
        if(arr[i] > k || arr[i] < (-k))     // if(prefix sum from 0 to i is greater than k or prefix sum from 0 to i if negative is less than -k) then the number of subarrays will increase.
            count++;
    }

    if(arr[0] > k || arr[0] < (-k)) count++;        // If first element is greater than k or less than -k then count increases.

    sort(arr.begin(), arr.end());       // Sort the prefix sum array.

    for(int i = 0; i<n; i++){
        count += n - (upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin());       // finding the index which is just greater than curr_sum + k and subtracting it from n.
    }                                                                                       // This will give all the elements which is greater than arr[i] + k (sum[0..j] > k + sum[0..i])
    
    return count;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int res = countSubarrays(arr, k);
    cout<<res<<endl;
    return 0;    
}