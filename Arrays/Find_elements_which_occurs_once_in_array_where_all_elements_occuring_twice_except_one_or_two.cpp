#include<bits/stdc++.h>
using namespace std;

// Idea is when we take xor of all the elements then if that two elements occuring once in x and y then after xor of all elements the 
// the xor will be x ^ y . So we take any set bit (say k) in this x ^ y then divide the array into two multiset in which one multiset contains
// those elements whose that kth element as set bit and another multiset contains unset bit then those will give the two numbers.
void twoElementOccurOnce(int arr[], int n){
    int a = arr[0], x = 0, y = 0;
    for(int i = 1; i<n; i++)
        a ^= arr[i];

    int set_bit = a & ~(a - 1); // Give the rightmost set bit

    for(int i = 0; i<n; i++){
        if(set_bit & arr[i])
            x ^= arr[i];
        else 
            y ^= arr[i];
    } 

    cout<<x<<" "<<y<<endl;
}

// Only one element occuring once and all other elements occurs twice.
// Simply do xor of all the elements and we get the element.
int elementOccurOnce(int arr[], int n){
    int x;
    for(int i =0; i<n; i++)
        x ^= arr[i];
    
    return x;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    //int res = elementOccurOnce(arr, n);
    //cout<<res<<endl;
    twoElementOccurOnce(arr, n);
    return 0;
}