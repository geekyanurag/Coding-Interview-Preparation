// Problem is to find the transpose of the matrix.
void transpose( int A[][N],int n) 
{ 
    int temp[N][N];
	for(int i = 0; i<n; i++){
	    for(int j = 0; j<n; j++){
	        temp[i][j] = A[j][i];
	    }
	}
	for(int i =0; i<n; i++){
	    for(int j =0; j<n; j++)
	        A[i][j] = temp[i][j];
	}
}