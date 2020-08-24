#include<bits/stdc++.h>
using namespace std;

// Problem is given a set of boards and set of painters k which take 1 unit time to paint 1 unit of board and you have to paint all the painters in minimum time.
// In other words minimize the maximum time to paint all the boards. We will use binary search. We assume mid to be the answer then check its correctness and if not correct then take answer to a mid from left half or right half and repeat the same until we find the answer.
// Painter can only paint continuous boards. eg. - boards - {10, 20, 30, 40} k = 2, ans = 60. A painter can paint 10, 20, 30 but not 10, 30 like this.
int getMax(int arr[], int n){
    int maxn = INT_MIN;
    for(int i = 0; i<n; i++)
        maxn = max(maxn, arr[i]);
    return maxn;
}

int getSum(int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n; i++)
        sum += arr[i];
    return sum;
}

int numPainters(int arr[], int n, int maxLength){  // Maxlength is the sum which should not cross the sum of consecutive array elements. If it crosses then the number of painters increases.
    int num = 1, sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        if(sum > maxLength){
            sum = arr[i];
            num++;
        }
    }
    return num;
}

int partition(int arr[], int n, int k){
    int low = getMax(arr, n);
    int high = getSum(arr, n);    // Maximum time one painter take to paint all the boards.

    while(low < high){
        int mid = (low + high) >> 1;
        int num = numPainters(arr, n, mid);
        if(num <= k)
            high = mid;
        else 
            low = mid + 1;
    }
    return low;
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int res = partition(arr, n, k);
    cout<<res<<endl;
    return 0;
}