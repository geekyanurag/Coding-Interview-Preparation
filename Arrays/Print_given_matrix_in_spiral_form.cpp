#include<bits/stdc++.h>
using namespace std;

// Printing the matrix in spiral form using four loops.
// Time = O(m * n) and space = O(1)
const int r = 3, c = 6;
void printSpiral(int arr[r][c], int m, int n){
    int k = 0, l = 0;

    while(k < m && l < n){
        for(int i = l; i<n; i++){
            cout<<arr[k][i]<<" ";
        }
        k++;

        for(int i = k; i<m; i++){
            cout<<arr[i][n-1]<<" ";
        }
        n--;

        if(k < m){
        for(int i = n-1; i>=l; i--){
            cout<<arr[m-1][i]<<" ";
        }
        m--;
        }

        if(l < n){
        for(int i = m-1; i>=k; i--){
            cout<<arr[i][l]<<" ";
        }
        l++;
        }
    }

}
int main(){
    int arr[r][c] = { { 1, 2, 3, 4, 5, 6 }, { 7, 8, 9, 10, 11, 12 },{ 13, 14, 15, 16, 17, 18 } };
    printSpiral(arr, r, c);
}