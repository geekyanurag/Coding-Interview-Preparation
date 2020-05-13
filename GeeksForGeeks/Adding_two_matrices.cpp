// Problem is to do the addition of two matrices.
void sumMatrix(int n1, int m1, int n2, int m2, int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]){
    int arr[n1][m1] = {0};
    if(n1 == n2 && m1 == m2){
        for(int i = 0; i<n1; i++)
            for(int j =0; j<m1; j++)
                arr[i][j] = arr1[i][j] + arr2[i][j];
        
        for(int i =0; i<n1; i++){
        for(int j =0; j<m1; j++)
            cout<<arr[i][j]<<" ";
    }
    }
    else
        cout<<"-1";
}