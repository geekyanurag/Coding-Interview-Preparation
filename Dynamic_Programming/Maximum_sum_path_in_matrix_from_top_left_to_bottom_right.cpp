#include<bits/stdc++.h>
using namespace std;

int sumPath(vector<vector<int>>arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>>sum(n + 1, vector<int>(m + 1));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + arr[i - 1][j - 1];
        }
    }
    return sum[n][m];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cin>>arr[i][j];
    }
    int ans = sumPath(arr);
    cout<<ans<<endl;
}