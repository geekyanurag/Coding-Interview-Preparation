#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int segregate(int arr[], int n){
    int i = 0;
    for(int j = 0; j<n; j++){
        if(arr[j]<=0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    return i;
}

int posNum(int arr[], int n){

    for(int i = 0; i<n; i++){
        if(arr[abs(arr[i]) - 1] < n && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }

    for(int i = 0; i<n; i++){
        if(arr[i] > 0)
            return i + 1;
    }
    return n + 1;
}

int findSmallestNum(int arr[], int n){
    int shift = segregate(arr, n);

    return posNum(arr + shift, n - shift);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    int res = findSmallestNum(arr, n);
    cout<<res<<endl;
    return 0;
}