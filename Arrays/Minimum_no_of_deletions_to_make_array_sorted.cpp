#include<bits/stdc++.h>
using namespace std;

// Finding the minimum no. of deletions to make an array sorted.
// Idea is to find the longest increasing subsequence then subtract the array length to the lis to get the min. no. of deletions.
int minDelete(int arr[], int n){
    int lis[n];
    for(int i = 0; i<n; i++)
        lis[i] = 1;

    for(int i = 1; i<n-1; i++){
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i] && lis[j] + 1 > lis[i])
                lis[i] = lis[j] + 1;
        }
    }
    int maxn = *max_element(lis, lis + n);
    int minDelete = n - maxn;
    return minDelete;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    int res = minDelete(arr, n);
    cout<<res<<endl;
    return 0;
}