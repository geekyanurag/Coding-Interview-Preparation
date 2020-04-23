#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int>g[maxn];
int vis[maxn];

void dfs(int u, int sum[]){
    vis[u] = 1;
    sum[u] = u;
    int mx = 0;
    for(int i : g[u]){
        if(!vis[i])
            dfs(i, sum);
        mx = max(mx, sum[i]);
    }
    sum += mx;
}

int main(){
    int v, n;
    cin>>v>>n;
    memset(vis, 0, sizeof(vis));
    int sum[v];
    for(int i =0; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    dfs(0, sum);
    for(int i = 0; i<v; i++){
        cout<<i<<" "<<sum[i]<<endl;
    }
}