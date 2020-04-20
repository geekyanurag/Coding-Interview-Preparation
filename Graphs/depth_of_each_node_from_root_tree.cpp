#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int>g[maxn];
int level[maxn];
int vis[maxn];
void depth(int u, int root){

    for(int i : g[u]){
        if(i == root)
            continue;
        level[i] = level[u] + 1;
        depth(i, u);
    }
}

void dfs(int u){
    vis[u] = 1;
    cout<<u<<" "<<level[u]<<endl;
    for(auto i : g[u]){
        if(!vis[i])
            dfs(i);
    }
}
int main(){
    int n;
    cin>>n;
    memset(level, 0, sizeof(level));
    memset(level, 0, sizeof(vis));
    for(int i =0; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    depth(0, 0);
    cout<<endl;
    dfs(0);
}