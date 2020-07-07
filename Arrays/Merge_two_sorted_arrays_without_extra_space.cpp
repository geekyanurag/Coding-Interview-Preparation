#include<bits/stdc++.h>
using namespace std;

// Given 2 sorted arrays we have to sort the whole array after merging then take the m elements to arr1 after sorting and n elements to arr2.
void merge(int arr1[], int arr2[], int m, int n){

    for(int i = n-1; i>=0; i--){
        int j, last = arr1[m-1];
        for(j = m-2; j>=0 && arr1[j] > arr2[i]; j--)
            arr1[j + 1] = arr1[j];
        if(j != m - 2 || last > arr2[i]){
                arr1[j + 1] = arr2[i];
                arr2[i] = last;
            } 
    }  
}

int main(){
    int m, n;
    cin>>m>>n;
    int arr1[m], arr2[n];
    for(int i = 0; i<m; i++)
        cin>>arr1[i];
    for(int j = 0; j<n; j++)
        cin>>arr2[j];
    merge(arr1, arr2, m, n);
    
    // Printing the arrays after merging
    for(int i = 0; i<m; i++)
        cout<<arr1[i]<<" ";
    cout<<endl;
    for(int j = 0; j<n; j++)
        cout<<arr2[j]<<" ";
    return 0;
}