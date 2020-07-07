#include<bits/stdc++.h>
using namespace std;

// The idea to store two numbers in one element.
// To get the original element we do arr[i] % k and to get the required max-min we do arr[i] / k.
// Time - O(n) and Space - O(1).
void maxMin(int arr[], int n){
    /* If not sorted then
    sort (arr, arr + n);
    */
    int min_idx = 0, max_idx = n-1;
    int k = arr[n-1] + 1;

    for(int i =0; i<n; i++){
        if(i & 1){
            arr[i] = (arr[min_idx] % k) * k + arr[i];
            min_idx++;
        }
        else{
            arr[i] = (arr[max_idx] % k) * k + arr[i];
            max_idx--;
        }
    }

    for(int i = 0; i<n; i++)
        cout<<arr[i] / k<<" ";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    maxMin(arr, n);
    return 0;
}