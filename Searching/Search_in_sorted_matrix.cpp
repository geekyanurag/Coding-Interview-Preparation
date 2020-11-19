#include<bits/stdc++.h>
using namespace std;

// Given a sorted matrix and you have to search a key in the matrix. The given matrix is a square matrix. For n x m matrix use r = m  - 1;
int search(vector<vector<int>>mat, int key){
    int n = mat.size();
    if(n == 0) return -1;

    int smallest = mat[0][0], largest = mat[n - 1][n - 1];      // If smallest is first element and largest is last element.
    if(key < smallest && key > largest) return -1;              // For n x m matrix use largest = mat[n - 1][m - 1].

    int l = 0, r = n -1;
    while(l < n && r >= 0){
        if(mat[l][r] == key){
            cout<<"key found at "<<l + 1<<" "<<r + 1<<endl;
            return 1;
        }
        else if(mat[l][r] > key) r--;
        else l++;
    }
    return -1;
}

int main(){
    int n, key;
    cin>>n>>key;
    vector<vector<int>>mat(n, vector<int>(n));
    /* for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cin>>mat[i][j];
    } */
    mat = { { 10, 20, 30, 40 }, { 15, 25, 35, 45 }, { 27, 29, 37, 48 }, { 32, 33, 39, 50 } };
    bool res = search(mat,key);
}