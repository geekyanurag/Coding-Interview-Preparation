#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4;
// dx and dy will the coordinates where we can go. So in a grid if there is given condition that from a location (x, y) it can go to 
// 4 direction up, left, bottom, right. So there possible coordinates are there in dx and dy, total of 4.
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int grid[maxn][maxn];
int vis[maxn][maxn];

void dfsGrid(int x, int y, int n, int m){
    vis[x][y] = 1;
    cout<<grid[x][y]<<" ";
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];   // From given x we have 4 choices
        int ny = y + dy[i];   // From given y we have 4 choices
        if(nx >=0 and nx<n and ny>=0 and ny<m and !vis[nx][ny]) dfsGrid(nx, ny, n, m);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cin>>grid[i][j];
    }
    dfsGrid(0, 0, n, m);
}