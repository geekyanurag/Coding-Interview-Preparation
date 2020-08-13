#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int>g[maxn];
int vis[maxn], in[maxn], low[maxn], timer;

void dfs(int u, int p){
    vis[u] = 1;
    in[u] = low[u] = timer++;      // Initially in time of nodes will be same as low time of node.

    for(auto v : g[u]){
        if(v == p) continue;

        if(vis[v] == 1){                  // If there is a backedge then node is visited.
            low[u] = min(in[v], low[u]);   // low time of node will be minimum of in-time of child and low time of node.
        }
        else{
            dfs(v, u);          // If not visited do dfs on its childrens.
            if(low[v] > in[u]){   // If low time of child is greater than in-time of its parent then it is a bridge.
                cout<<u<<"-"<<v<<" is a bridge"<<endl;
            }
            low[u] = min(low[u], low[v]);       // Then update the low time of parent as minimum of low time of node and child.
        }
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
    timer = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i])
            dfs(i, -1);
    }

    return 0;
}