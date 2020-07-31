#include<bits/stdc++.h>
using namespace std;

// Dfs in tree. Here we don't require visited array because in tree there is no cycle. We only have to check if the given node doesn't go to its parent.
const int maxn = 1e5;
vector<int>g[maxn];
int vis[maxn];

void dfs(int u, int p){
	vis[u] = 1;
	cout<<u<<" ";
	for(auto i : g[u]){
		if(i == p) continue;
		dfs(i , u);
	}
}

int main(){
	int n;
	cin>>n;
	memset(vis, 0, sizeof(vis));
	for(int i =0; i<n; i++){
		int x, y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0, -1); // We are traversing from node 0 as root and root has no parent so its parent is -1.
}			