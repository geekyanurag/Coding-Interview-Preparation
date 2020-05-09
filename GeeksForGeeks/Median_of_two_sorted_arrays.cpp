// Problem is given two sorted arrays we have to find the median from the array formed by merging of both the arrays. 
int median(int arr[], int n, int brr[], int m){
    int i = 0, j = 0, k = 0, res;
    int temp[n + m];
    while(i < n && j < m){       // Both i and j should be less than the respective array sizes ie n and m.
        if(arr[i] <= brr[j]){
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = brr[j++];
        }
    }
    while(i < n){
        temp[k++] = arr[i++];
    }
    while(j < m){
        temp[k++] = brr[j++];
    }
    if((n + m) % 2 == 0){
        int mid = (n + m) / 2;
        res = (temp[mid] + temp[mid - 1]) / 2;
    }
    else {
        int mid = (n + m) / 2;
        res = temp[mid];
    }
    return res;
}
// arr : given array with size n 
// brr : given array with size m
int findMedian(int arr[], int n, int brr[], int m){
    int res = median(arr, n, brr, m);
    return res;
}