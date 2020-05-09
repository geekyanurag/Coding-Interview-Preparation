// Problem is to find the missing number from the positive numbers of the array as the array includes -ve numbers also.
int findMissing(int arr[], int n) { 
    int maxn, res = -1;
    unordered_map<int,int>mp;
    for(int i = 0; i<n; i++)
        if(arr[i] >= 0)
            mp[arr[i]]++;
    maxn = *max_element(arr, arr + n);
    for(int i = 1; i<=maxn; i++){
        if(mp.find(i) == mp.end()){
            res = i;
            break;
        }
    }
    if(res == -1)
        res = maxn + 1;
    return res;
}