#include<bits/stdc++.h>
using namespace std;

// Efficient Approach
// Uses the gap technique. Initially the gap will be the sum of lengths of the array. Then it will decrease after one iteration to ceil(gap / 2).
// Time complexity - O((n + m) * log(n + m))
int nextgap(int gap){
    if(gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge2(int arr1[], int arr2[], int m, int n){
    int i, j, gap = m + n;
    for(gap = nextgap(gap); gap > 0; gap = nextgap(gap)){
        
        // comparing elements in the first array
        for(i = 0; i + gap < m; i++){
            if(arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }
        // comparing elements in the first and second array
        for(j = gap > m ? gap - m : 0 ; i < m && j < n ; i++, j++){
            if(arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);
        }
        // comparing elements in the second array
        if(j < m){
            for(j = 0; j + gap < n; j++){
                if(arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }
    }
}

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
    //merge(arr1, arr2, m, n);
    merge2(arr1, arr2, m, n);
    // Printing the arrays after merging
    for(int i = 0; i<m; i++)
        cout<<arr1[i]<<" ";
    cout<<endl;
    for(int j = 0; j<n; j++)
        cout<<arr2[j]<<" ";
    return 0;
}