#include<bits/stdc++.h>
using namespace std;

// Calculating height of a general tree.
const int maxn = 1e5;

vector<int>g[maxn];
int height[maxn];

void dfs(int u, int p){
    height[u] = 0;
    for(auto i : g[u]){
        if(i == p) continue;
        dfs(i, u);
        height[u] = max(height[u], 1+height[i]);    // height of the parent will be max (height of the tree , 1 + (height of its childrens) ).
    }
}

// This is another approach of finding the height of the tree.
void dfs1(int u, int p){
    height[u] = 0;
    int mx = -1;

    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        mx = max(mx, height[v]);  // mx is the maximum height of all the heights of its childrens.
    }
    height[u] += 1 + mx;  // height of the root will be 1 + maximum of all the heights of its childrens and add to parent.
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
    dfs(0, -1);
    cout<<height[0]<<endl;  // Height of the root.
}