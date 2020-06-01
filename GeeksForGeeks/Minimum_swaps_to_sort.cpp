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

// Efficient approach is to use the graph cycle technique.
// In this technique we take the elements which are being swapped , if 2 no's are to be swapped then the min no. of swapping is 2 - 1 = 1,
// so if n is the number of elements then the min swaps is n - 1. So ans = summation of no. of cycles * (sizeofcycle - 1);
int minSwaps(int A[], int N){
    pair<int,int> arr[N];
    for(int i =0; i<N; i++){
        arr[i].first = A[i];
        arr[i].second = i;
    }
    sort(arr, arr + N);
    vector<bool>vis(N , false);
    int ans = 0;
    for(int i = 0; i<N; i++){
        if(vis[i] || arr[i].second == i)
            continue;
        int j = i, size = 0;
        while(!vis[j]){
            vis[j] = 1;
            j = arr[j].second;
            size++;
        }
        if(size > 0)
            ans += size - 1;
    }
    return ans;
}