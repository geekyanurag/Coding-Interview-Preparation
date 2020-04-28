#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int>g[maxn];
int vis[maxn];

void dfs(int u){
	vis[u] = 1;
	cout<<u<<" ";
	for(auto i : g[u]){
		if(!vis[i])
			dfs(i);
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
	}
	dfs(0);
}			