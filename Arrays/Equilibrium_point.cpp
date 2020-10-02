#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Problem is to find the point where sum of all the elements from left is equal to sum of all the elements from right.
// e.g = arr = {1, 3, 5, 2, 2} ans = 3 (3rd number ie 5, 1- based indexing). So 5 is the equilibrium point where sum of left = 4 and sum of right = 4
// Solution is to just take sum of all array elements and maintain a cumulative sum. Cumulative sum will maintain sum of left and sum of right = (total_sum - curr_sum)
int solve(vector<ll>arr){
    ll n = arr.size();
    if(n == 1){        // if only 1 element is there then that is the equilibrium point.
        return 1;
    }
    if(n == 2){      // if no. of elements is 2, no equilibrium point exists.
        return -1;
    }
    
    ll total_sum = 0, curr_sum = 0;
    for(int i = 0; i<n; i++)
        total_sum += arr[i];
    
    curr_sum += arr[0];
    ll ans = 0;
    for(int i = 1; i<n - 1; i++){
        if(curr_sum == (total_sum - (curr_sum + arr[i]))){         // Condition for the equilibrium point
            ans = i + 1;
            break;
        }
        curr_sum += arr[i];
    }
    if(ans == 0) ans = -1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        ll ans = solve(arr);
        cout<<ans<<endl;
    }
    return 0;
}