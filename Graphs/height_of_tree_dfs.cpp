#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

void dfs(vector<int>g[], vector<int>&vis, int u, int height[]){
    vis[u] = 1;
    height[u] = 0;
    cout<<u<<" ";
    for(auto i : g[u]){
        if(!vis[i]){
            dfs(g, vis, i, height);
        }
        height[u] = max(height[u], 1+height[i]);
    }
}
int main(){
    int v, n;
    cin>>v>>n;
    vector<int>g[v];
    vector<int>vis(v, 0);
    int height[v];
    for(int i =0; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        //g[y].push_back(x);
    }
    dfs(g, vis, 0, height);
    for(int i =0; i<v; i++){
        cout<<i<<" "<<height[i]<<endl;
    }
}