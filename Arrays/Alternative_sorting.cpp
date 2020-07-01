#include<bits/stdc++.h>
using namespace std;

// Sort elements such that first element is first max and second element is first min and so on.
void altSort(int arr[], int n){
    sort(arr, arr + n);

    int i = 0, j = n-1;
    while(i < j){
        cout<<arr[j--]<<" "<<arr[i++]<<" ";
    }
    if(n & 1)
        cout<<arr[i]<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    altSort(arr, n);
    return 0;
}