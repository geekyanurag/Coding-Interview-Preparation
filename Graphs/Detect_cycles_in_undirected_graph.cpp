#include<bits/stdc++.h>
using namespace std;

// Detect Cycles in an undirected Graph
const int maxn = 1e5;
vector<int>g[maxn];
int vis[maxn];

bool isCycle(int u, int p){
    vis[u] = 1;

    for(auto v : g[u]){
        if(v == p) continue;
        if((!vis[v] && isCycle(v, u)) || vis[v] == 1) return true;
    }
    vis[u] = 2;
    return false;
}

bool hasCycle(int n){
    
    for(int i = 0; i<n; i++){     // For each connected components it will check if it has cycle or not.
        if(!vis[i] && isCycle(i, -1)) return true;
    }
    return false;
}

int main(){
    int v, n;
    cin>>v>>n;
    for(int i =0; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(hasCycle(v)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

}