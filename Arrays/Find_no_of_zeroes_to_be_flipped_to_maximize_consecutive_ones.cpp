#include<bits/stdc++.h>
using namespace std;

// find the index of zeroes which after flipping gives the maximum length consecutive 1's in the array.
void numZeroesFlipped(int arr[], int n, int m){
    int left = 0, right = 0, numZeroes = 0;
    int low = 0, max_size = 0;

    while(right < n){
        if(numZeroes <= m){
            if(arr[right] == 0){
                numZeroes++;
            }
            right++;
        }

        if(numZeroes > m){
            if(arr[left] == 0){
                numZeroes--;
            }
            left++;
        }

        if((right - left) > max_size && numZeroes <= m){
            max_size = right - left;
            low = left;
        }
    }

    for(int i = low; i<=max_size; i++){
        if(arr[i] == 0)
            cout<<i<<" ";
    }

}

int main(){
    int n, m;
    cin>>n>>m;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    numZeroesFlipped(arr, n, m);
    return 0;
}