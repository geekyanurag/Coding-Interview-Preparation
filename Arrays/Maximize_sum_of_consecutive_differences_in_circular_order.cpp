//Given array of integers we have to maximize the sum of consecutive diffences in circular array.
// e.g = arr = {1, 4, 8, 2} so we can rearrange the array as arr = {1, 8, 2, 4} so diff be like |1 - 8| + |8 - 2| like this so ans = 18.
// The idea is to sort the elements and then we can see that all the elements from a1 to a(n/2) will be subtracted twice and all
// the elements from a(n /2 ) + 1 to an will be added twice.
#include<bits/stdc++.h>
using namespace std;

int maximize(int arr[], int n){
    int sum = 0;
    sort(arr, arr + n);
    for(int i = 0; i<n/2; i++){
        sum -= 2 * arr[i];
        sum += 2 * arr[n - i - 1];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    int res = maximize(arr, n);
    cout<<res<<endl;
    return 0;
}