// Search in a sorted matrix.
int search( int n,int m, int x, int mat[SIZE][SIZE])
{
    int res = 0;
   for(int i =0; i<n; i++){
       for(int j =0; j<m; j++){
           if(mat[i][j] == x){
               res = 1;
               break;
           }
       }
   }
   return res;
}

// Using divide and conquer algorithm.
int search1(int n, int m, int x, int mat[SIZE][SIZE]){
    if(n == 0 && m == 0)
        return -1;
    int smallest = mat[0][0], largest = mat[n-1][m-1];
    if(x < smallest || x > largest)
        return -1;
    int i = 0, j = m - 1;
    while(i < n && j >= 0){
        if(mat[i][j] == x)
            return 1;
        if(mat[i][j] > x)
            j--;
        if(mat[i][j] < x)
            i++;
    }
    return 0;
}