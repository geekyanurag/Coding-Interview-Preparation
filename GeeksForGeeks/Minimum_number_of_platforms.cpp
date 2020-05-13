// Problem is to find the minimum no. of platforms needed to take all the trains given arriving and departure times of the train.
// e.g = arrival = {0930, 0945, 1200} and departure = {1000, 1230, 1300};
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int plat = 1, result = 1, i = 1, j =0;
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            plat++;
            i++;
        }
        else if(arr[i] > dep[j]){
            plat--;
            j++;
        }
        result = max(result, plat);
    }
    return result;
}