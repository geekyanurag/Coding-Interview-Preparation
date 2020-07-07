#include<bits/stdc++.h>
using namespace std;

// Find the missing number and repeated number in a set of integers ranging from 1 to n.
// Method - 1 using sum of all the elements and square-sum of all the elements
// Idea is take sum and square-sum of all the array elements and sum and square-sum of all numbers from 1 to n.
/* let there are 4 elements w, x, y, z then sum = w + x + y + z and array elements are w, x, x, z so subtracting them we get y - x.
Similarly difference of square of all elements and square of all array elements is (y2 - x2) y2 = y square. So we it can be written as (y - x) * (y + x) . 
So we can find x and y ie both repeating and missing number. */ 
void solve(int arr[], int n){
    int sum = 0, sum2 = 0, arr_sum = 0, arr_sum2 = 0;
    for(int i =0; i<n; i++){
        arr_sum += arr[i];
        arr_sum2 += arr[i] * arr[i];
    }

    for(int i = 1; i<=n; i++){
        sum += i;
        sum2 += i * i;
    }
    int x = sum - arr_sum;
    int y = sum2 - arr_sum2;
    int z = y / x;
    int a = (z + x) / 2;
    int b = a - x;
    cout<<a<<" "<<b<<endl;
}

// Method 2 Using Sorting
// Time = O(nlogn) Space = O(1)
void solve3(int arr[], int n){
    sort(arr, arr + n);
    int repeat, missing = 0;
    for(int i = 0; i<n-1; i++){
        if(arr[i] == arr[i + 1])
            repeat = arr[i];
    }
    for(int i = 0; i<n; i++){
        if(arr[i] != i + 1 && i + 1 != repeat)
            missing = i + 1;
    }
    cout<<missing<<" "<<repeat<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    solve(arr, n);
    solve3(arr, n);
    return 0;
}