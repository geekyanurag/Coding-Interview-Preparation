#include<bits/stdc++.h>
using namespace std;

//This method takes O(n) time but space complexity is more
vector<int> product(vector<int>arr){
    int n = arr.size();
    vector<int>prod(n), left(n), right(n);
    left[0] = 1;
    right[n-1] = 1;
    for(int i =1; i<n; i++){
        left[i] = arr[i-1] * left[i-1];
    }
    for(int i = n-2; i>=0; i--){
        right[i] = arr[i+1] * right[i+1];
    }
    for(int i =0; i<n; i++){
        prod[i] = left[i] * right[i];
    }
    return prod;
}

// To reduce space complexity we perform both left and right multiplication in single array.
vector<int> product1(vector<int>arr){
    int n = arr.size();
    vector<int>prod(n);
    int temp = 1;
    for(int i =0; i<n ; i++){
        prod[i] = temp;
        temp *= arr[i];
    }
    temp = 1;
    for(int i = n-1; i>=0; i--){
        prod[i] *= temp;
        temp *= arr[i];
    }
    return prod;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i =0; i<n; i++)
        cin>>arr[i];
    vector<int> res = product1(arr);
    for(int i =0; i<n; i++)
        cout<<res[i]<<" ";
}