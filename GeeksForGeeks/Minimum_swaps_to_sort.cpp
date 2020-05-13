// Problem is to count the minimum number of swaps to sort the array.
// Idea is to use the method of selection sort.
int minSwaps(int A[], int N){
    int count = 0;
    for(int i = 0; i<N; i++){
        int min = i;
        for(int j = i+1; j<N; j++){
            if(A[min] > A[j])
                min = j;
        }
        if(min != i){
            int temp = A[min];
            A[min] = A[i];
            A[i] = temp;
            count++;
        }
    }
    return count;
}