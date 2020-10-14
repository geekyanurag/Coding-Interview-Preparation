#include<bits/stdc++.h>
using namespace std;

// Finding the total number of unique paths to go from (0, 0) to (r, c).
// The constraint is that we can only go either left or down. The grid is filled with obstackle. 0 is represented as free path and 1 as obstackle.
int uniquePaths(vector<vector<int>>&grid){
    int r = grid.size(), c = grid[0].size();
    vector<vector<int>>paths(r, vector<int>(c, 0));

    if(grid[0][0] == 0) paths[0][0] = 1;
    for(int i = 1; i<r; i++){               // Filling first column
        if(grid[i][0] == 0)
            paths[i][0] = paths[i - 1][0];
    }

    for(int i = 1; i<c; i++){
        if(grid[0][i] == 0)
            paths[0][i] = paths[0][i - 1];          // Filling first row
    }

    for(int i = 1; i<r; i++){
        for(int j = 1; j<c; j++){
            if(grid[i][j] == 0)
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];        // Total number of ways from up and left.
        }
    }

    return paths[r - 1][c - 1];
}

int main(){
    vector<vector<int>>grid = {{0, 0 , 0}, {0, 1, 0}, {0, 0, 0}};

    cout<<uniquePaths(grid)<<endl;
    return 0;
}

