#include<bits/stdc++.h>
using namespace std;

// This solution finds whether the given array have a sorted subsequence of size 3 or not. If yes print one.
void sortedSubsequence(int arr[], int n){
    int min = 0, max = n-1;

    int smaller[n], greater[n];
    smaller[0] = -1;

    for(int i =1; i<n; i++){
        if(arr[i] <= arr[min]){
            min = i;
            smaller[i] = -1;
        }
        else 
            smaller[i] = min;
    }

    greater[n-1] = -1;
    for(int i = n-2; i>=0; i--){
        if(arr[i] >= arr[max]){
            max = i;
            greater[i] = -1;
        }
        else 
            greater[i] = max;
    }

    for(int i =0; i<n; i++){
        if(smaller[i] != -1 && greater[i] != -1)
            cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[greater[i]]<<endl;
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    sortedSubsequence(arr, n);
    return 0;
}