#include<bits/stdc++.h>
using namespace std;

//Given a set of integers ranging from 0 to n-1 and we have to find the duplicates.
// the idea is simple just make arr[abs(arr[i])] as -arr[abs(arr[i])] and if arr[abs(arr[i])] < 0 then that no. already appeared in array so print that.
void findingDuplicates(int arr[], int n){
    for(int i =0; i<n; i++){
        if(arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else 
            cout<<abs(arr[i])<<endl;
    }
}

// Another method is that we can use a boolean array to store the frequency of the array.
// Time is O(n) and space is O(n).
void findingDuplicates2(int arr[], int n){
    int res[n];
    int num;
    for(int i =0; i<n; i++)
        res[i] = 0;
    for(int i = 0; i<n; i++){
        res[arr[i]]++;
    }

    for(int i =0; i<n; i++){
        if(res[arr[i]] > 1)
            num = arr[i];
    }
    cout<<num<<endl;
} 

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    findingDuplicates2(arr, n);
    findingDuplicates(arr, n);
    return 0;
}