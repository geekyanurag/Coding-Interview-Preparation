// Problem is given two different sized matrices then we have to multiply the matrices. Here n = no. of rows and m = no. of cols.
void multiplyMatrix(int n1, int m1, int n2, int m2, long long arr1[SIZE][SIZE], long long arr2[SIZE][SIZE]){
    int res[SIZE][SIZE];
    if((m1 == n2)){
        for(int i =0; i<n1; i++){
            for(int j =0; j<m2; j++){
                res[i][j] = 0;
                for(int k = 0; k<n2; k++){
                    res[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        
        for(int i = 0; i<n1; i++){
            for(int j = 0; j<m2; j++)
                cout<<res[i][j]<<" ";
        }
    }
    else
        cout<<"-1";
    
}