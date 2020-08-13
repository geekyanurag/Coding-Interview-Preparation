#include<bits/stdc++.h>
using namespace std;

// Topological sort is possible in directed acyclic graph.
// The idea is to run dfs and after visiting all the node it will push that to the result. Similarly for all the nodes.
const int maxn = 1e4;
vector<int>g[maxn];
vector<int>ans;
vector<int>vis(maxn);

void dfs(int u){
    vis[u] = 1;

    for(auto v : g[u]){
        if(!vis[v])
            dfs(v);
    }
    ans.push_back(u);
}

void topSort(int n){
    for(int i = 0; i<n; i++){
        if(!vis[i])
            dfs(i);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    topSort(n);
    reverse(ans.begin(), ans.end());
    for(auto i : ans){
        cout<<i<<" ";
    }
}