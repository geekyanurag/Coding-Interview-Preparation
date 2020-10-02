#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Given arrival and departure times of different trains, we have to calculate minimum number of platforms needed so that trains at a given time can be accomodated.
// Solution is first sort the timings of arr and dep then take two pointer one points to arrival of second train and another points to dep of first train.
// If arrival time of second train is less than the departure time of first train that means we have to increment the platform number and then increment first pointer.
// And if arrival time of second train is greater than departure time of first than platform needed will be decreased.
int min_platforms(vector<int>arr, vector<int>dep){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int cnt = 1, maxn = 1;
    int i = 1, j = 0;
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            cnt++;
            i++;
        }
        else if(arr[i] > dep[j]){
            cnt--;
            j++;
        }
        maxn = max(maxn, cnt);
    }
    return maxn;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n), dep(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        for(int j = 0; j<n; j++)
            cin>>dep[j];
        int ans = min_platforms(arr, dep);
        cout<<ans<<endl;
    }
    return 0;
}