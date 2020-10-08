#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Printing all the subarrays. There are total of n * (n + 1) / 2 subarrays.
// e.g = 1, 2, 3 ; for 1 there are n subarrays posssible, for 2 there are n - 1 subarrays and for 3 n - 2. So similarly n + (n - 1) + (n - 2) + ....+2 + 1 = n * (n + 1) / 2.
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    // There will be starting point and ending point so s will be from 0 to n and ending point e will be from s to n and from s to e is a subarray.
    for(int s = 0; s<n; s++){
        for(int e = s; e < n; e++){
            for(int k = s; k <= e; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}