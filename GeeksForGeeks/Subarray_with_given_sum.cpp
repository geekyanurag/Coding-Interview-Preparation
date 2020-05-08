// Problem is to find the index of starting and ending of subarray with sum = k and indexing start from 1.
void subarraySum(int arr[], int n, int s){
    int sum = arr[0], i = 0; 
    for(int j =1; j<=n; j++){
        while(sum > s && i < j-1){
            sum -= arr[i];
            i++;
        }
        if(sum == s){
            cout<<i + 1<<" "<<j;
            break;
        }
        if(j < n){
            sum += arr[j];
        }
    }
    if(sum != s)
        cout<<"-1";
}