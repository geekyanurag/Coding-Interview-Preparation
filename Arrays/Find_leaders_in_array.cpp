#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Problem is to find the numbers which is maximum from all the elements in the right side of that element. Also the last element is also maximum.
// Solution is just maintain a variable that will maintain the maximum number from the right side of array.
vector<int> solve(vector<int>arr){
    int n = arr.size();
    int maxn = arr[n - 1];
    vector<int>ans;
    
    if(n == 1){
        ans.push_back(arr[0]);
        return ans;
    }
    
    ans.push_back(arr[n - 1]);
    for(int i = n - 2; i >= 0; i--){            // Iterating from right side
        if(arr[i] >= maxn){                     // if current element is maximum from the maximum so far than push it to result array and then update maxn
            ans.push_back(arr[i]);
            maxn = arr[i];
        }
    }
    
    reverse(ans.begin(), ans.end());            // Since the number are in reverse order in array, we have to reverse it again.
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
        vector<int>arr(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        vector<int>res = solve(arr);
        for(auto i : res) cout<<i<<" ";
        // for(auto i = res.begin(); i!=res.end(); i++)
        //     cout<<*i<<" ";
        cout<<endl;
    }
    return 0;
}