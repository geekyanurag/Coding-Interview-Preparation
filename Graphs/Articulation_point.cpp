#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int>g[maxn];
vector<int>vis(maxn), in(maxn, -1), low(maxn, -1);
set<int>res;
int timer;

void dfs(int u, int p){
    vis[u] = 1;
    in[u] = low[u] = timer++;
    int children = 0;

    for(auto v : g[u]){
        if(v == p) continue;
        if(vis[v]){
            low[u] = min(low[u], in[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[v], low[u]);
            if(low[v] >= in[u] && p != -1){
                res.insert(u);
            }
            children++;
        }
    }
    if(p == -1 && children > 1)
        res.insert(u);
}

int main(){
    int v, n;
    cin>>v>>n;
    for(int i = 0; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    timer = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i])
            dfs(i, -1);
    }
    for(auto i : res)
        cout<<i<<" ";
}