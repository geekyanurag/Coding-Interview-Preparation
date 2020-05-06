#include<bits/stdc++.h>
using namespace std;

// Method - 1 is to count the no. of ones then change the no. of array till the count of 0 to 0 and rest to 1.
void segregate(int arr[], int n){
    int count = 0;
    for(int i =0; i<n; i++)
        if(arr[i] == 0)
            count++;
    for(int i =0; i<count; i++)
        arr[i] = 0;
    for(int i = count; i<n; i++)
        arr[i] = 1;
}

// Method - 2 is to take two pointer one from starting and other from end and find the left most 0 which is in continuation and rightmost 0 which is in continuation and change them.
// e.g = 0, 0, 1, 0, 1, 1, 0, 1 so first the leftmost continued 0 is at index 1 and rightmost continued 1 is at index last so left index will be 0 and right index be 1 and left++ and right++.
void segregate1(int arr[], int n){
    int left = 0, right = n - 1;
    while(left < right){
        while(arr[left] == 0 && left < right)
            left++;
        while(arr[right] == 1 && left < right)
            right--;
        if(left < right){
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    //segregate(arr, n);
    segregate1(arr, n);
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}