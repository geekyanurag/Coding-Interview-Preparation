// Problem is to find the first element which occurs more than once in the array and whose index is the smallest.
int firstRepeated(int arr[], int n) {
    unordered_map<int,int>mp;
    int idx = -1;
    for(int i =0; i<n; i++)
        mp[arr[i]]++;
    for(int i =0; i<n; i++){
        if(mp[arr[i]] > 1){
            idx = i + 1;
            break;
        }
    }
    return idx;
}