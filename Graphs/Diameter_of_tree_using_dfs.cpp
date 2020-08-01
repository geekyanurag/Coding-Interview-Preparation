#include<bits/stdc++.h>
using namespace std;

// Finding diameter of a tree using dfs. Diameter is the maximum distance between two nodes.
// The idea is we first find the node from root which is farthest from root (say x) and then again we find the node which is farthest from x , so the distance between them is the diameter. 
const int maxn = 1e3;
vector<int>g[maxn];
pair<int,int>best;    // This will store the maximum length and the node having that length from root.

void dfs(int u, int p, int len){
    best = max(best, {len, u});     // Store the maximum length from parent root to a given node having maximum depth.

    for(auto i : g[u]){
        if(i == p) continue;
        dfs(i, u, len + 1);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    best = {-1, -1};
    int first = 1;
    dfs(first, -1, 0);
    int second = best.second;
    best = {-1, -1};
    dfs(second, -1, 0);
    cout<<best.first<<endl;
}