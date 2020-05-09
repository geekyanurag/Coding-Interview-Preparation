// Problem is to find the element which is smaller than given element but closest to the element value.
int immediateSmaller(int arr[], int n, int x)
{
    int maxn = -1;
    for(int i =0; i<n; i++){
        if(arr[i] < x){
            maxn = max(maxn, arr[i]);
        }
    }
    return maxn;
}