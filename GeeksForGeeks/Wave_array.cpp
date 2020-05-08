// Given a sorted array then sort the elements like a[i] >= a[i+1] <= a[i+2] like this.
void convertToWave(int *arr, int n){
    for(int i = 1; i<n; i+=2){
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }
}