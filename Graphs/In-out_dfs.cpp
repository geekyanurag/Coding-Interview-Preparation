#include<bits/stdc++.h>
using namespace std;

// Finding the height of all the nodes considering each node as root. All the heights are stored in dp[maxn].
const int maxn = 1e5;
vector<int>g[maxn];
int in[maxn], out[maxn], dp[maxn];

void dfs1(int u, int p){
    in[u] = 0;

    for(auto v : g[u]){
        if(v == p) continue;
        dfs1(v, u);

        in[u] = max(in[u], 1 + in[v]);
    }
}

void dfs2(int u, int p){
    int mx1 = -1, mx2 = -1;

    for(auto v : g[u]){
        if(v == p) continue;

        if(in[v] >= mx1){
            mx2 = mx1;
            mx1 = in[v];
        }
        else if(in[v] > mx2) mx2 = in[v];
    }
    
    for(auto v : g[u]){
        if(v == p) continue;

        int use = mx1;
        if(mx1 == in[v])
            use = mx2;
        out[v] = max(1 + out[u], 2 + use);

        dfs2(v, u);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs1(0, -1);
    dfs2(0, -1);
    for(int i = 0; i<n; i++)
        dp[i] = max(in[i], out[i]);
    
    for(int i = 0; i<n; i++)
        cout<<dp[i]<<" ";

}