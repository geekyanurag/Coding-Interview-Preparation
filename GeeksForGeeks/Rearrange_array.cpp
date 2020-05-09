// Problem is to rearrange array in such a way that arr[i] = arr[arr[i]] and numbers in array are in range(0, n - 1);
void arrange(long long arr[], int n) {
    for(int i =0; i<n; i++){
        arr[i] += (arr[arr[i]] % n) * n;
    }
    for(int i = 0; i<n; i++)
        arr[i] /= n;
}