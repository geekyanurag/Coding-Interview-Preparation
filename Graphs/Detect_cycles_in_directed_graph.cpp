#include<bits/stdc++.h>
using namespace std;

// Detect cycle in a directed graph
// Use the concept of coloring. 
const int maxn = 1e3;
vector<int>g[maxn];
vector<int>color(maxn); // Initially all the nodes are colored white ie(0)

bool isCycle(int u){
    color[u] = 1;  // color the node as grey ie(1)

    for(auto v : g[u]){
        if(color[v] == 0){
            if(isCycle(v))
                return true;
        }
        else if(color[v] == 1){
            return true;
        }
    }
    color[u] = 2;  // After coming out of the node the color of node becomes black(2)
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
    }

    bool res = false;
    for(int i = 0; i<n; i++){
        if( color[i] == 0 && isCycle(i))
            res = true;
    }
    cout<<res<<endl;
}