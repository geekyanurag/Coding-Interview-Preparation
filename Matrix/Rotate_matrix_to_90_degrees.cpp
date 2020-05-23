#include<bits/stdc++.h>
using namespace std;

const int n = 4;
// Rotating the matrix into anticlockwise direction.
// Idea is to take each square as one loop so each such squares.
void rotateMatrix(int arr[n][n]){
    for(int i =0; i<n/2; i++){
        for(int j = i; j<n-i-1; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][n-i-1];
            arr[j][n-i-1] = arr[n-i-1][n-j-1];
            arr[n-i-1][n-j-1] = arr[n-j-1][i];
            arr[n-j-1][i] = temp;
        }
    }
}

// For rotating into clockwise direction.
void rotateMatrix1(int arr[n][n]){
    for(int i = 0; i<n/2 ; i++){
        for(int j = i ; j<n-i-1; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[n - j - 1][i];
            arr[n - j -1] = arr[n - j - 1][n - i - 1];
            arr[n - j - 1] = arr[j][n - i - 1];
            arr[j][n - i - 1] = temp;
        }
    }
}

void printMatrix(int arr[n][n]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    int arr[n][n] = { { 1, 2, 3, 4 }, 
                      { 5, 6, 7, 8 }, 
                      { 9, 10, 11, 12 }, 
                      { 13, 14, 15, 16 } };
    rotateMatrix(arr);
    printMatrix(arr);
    return 0;
}