#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int minDiff(int arr[], int n, int k){
    deque<int>q(k);
    int i;
    for(i = 0; i<k; i++){
        while(!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }

    int minm = INT_MAX;

    for( ; i<n; i++){
        minm = min(minm, arr[q.front()]);

        while(!q.empty() && q.front() <= i - k)
            q.pop_front();
        
        while(!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);

    }

    minm = min(minm, arr[q.front()]);
    
    return minm;
}

int minDifference(int arr[], int n, int k){
    int diff[n-1];

    for(int i = 0; i<n-1; i++){
        diff[i] = arr[i+1] - arr[i];
    }

    int ans = minDiff(diff, n-1, n-k-1);

    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int ans = minDifference(arr, n, k);
    cout<<ans<<endl;
}