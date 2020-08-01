#include<bits/stdc++.h>
using namespace std;

// Finding the maximum sum from root to leaf.
const int maxn = 1e5;
vector<int>g[maxn];
int sum[maxn];  // All global variables are initialized to 0.

void dfs(int u, int p){
    sum[u] = u;   // Stores the value of the nodes to sum array initially.
    int mx = 0;

    for(int i : g[u]){
        if(i == p) continue;
            dfs(i, u);   // Going to the leaf
        mx = max(mx, sum[i]); // calculating max value among all the childrens of parent u.
    }
    sum[u] += mx; // Adding the max value to the parent.
}

int main(){
    int v, n;
    cin>>v>>n;
    for(int i =0; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    dfs(0, -1);
    cout<<sum[0]<<endl;
}