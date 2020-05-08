// Problem is to find to return all the elements of an array which is greater than or equal to the element of its right.
vector<int> leaders(int arr[], int n){
    vector<int>res;
    res.push_back(arr[n-1]);
    for(int i = n-2; i>=0; i--){
        if(arr[i] >= res.back())
            res.push_back(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}