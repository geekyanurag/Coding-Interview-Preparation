#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int>g[maxn];
int vis[maxn];

void dfs(int u, int dest, int &cnt){
    vis[u] = 1;
    if(u == dest)
        cnt++;
    else{
    for(int i : g[u]){
        if(!vis[i])
            dfs(i, dest, cnt);
    }
    }
    vis[u] = 0;
}

int main(){
    int v, n, dest, cnt = 0;
    cin>>v>>n;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i<v; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    dfs(0, 3, cnt);
    cout<<cnt<<endl;
}