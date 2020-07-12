#include<bits/stdc++.h>
using namespace std;

// We have to find all possible pair sum in an array. e.g = arr = [1, 5, 6] then possible pairs are (1, 1), (1, 5), (1, 6) .. similarly for
// 5 and 6. So in this case all the pair sum will occur twice so their xor will be 0 except the pair having same number like (1, 1) . So the 
// answer will be the xor of twice of all the array elements.
int xorPairSum(int arr[], int n){
    int x = 0;

    for(int i = 0; i<n; i++)
        x ^= arr[i];
    
    /* OR
    for(int i = 0; i<n; i++)
        x ^= (2 * arr[i]);
    
    return x;
    */
    return 2*x;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int res = xorPairSum(arr, n);
    cout<<res<<endl;
    return 0;
}