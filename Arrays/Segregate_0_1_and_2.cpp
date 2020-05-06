#include<bits/stdc++.h>
using namespace std;

// This Algorithm is also known as dutch national flag algorithm or 3-way Partitioning problem.
//Method - 1; taking 3 variables low, mid, high then if arr[mid] == 0 then swap arr[low], arr[mid] then increment both; 
//if arr[mid == 1] increment mid and if arr[mid] == 2 then swap(arr[mid], arr[high]) then decrement high only.
void segregate(int arr[], int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            int temp = arr[low];  // swap(arr[low++], arr[mid++]);
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;       
        }
        else{
            int temp = arr[mid];
            arr[mid] = arr[high];  // swap(arr[mid], arr[high--]);
            arr[high] = temp;
            high--;
        }

    }
}

// Method - 2 Calculating the no. of 0's and 1's then update it in array.
void segregate1(int arr[], int n){
    int count_0 = 0, count_1 = 0;
    for(int i =0; i<n; i++){
        if(arr[i] == 0)
            count_0++;
        if(arr[i] == 1)
            count_1++;
    }
    for(int i =0; i<count_0; i++)
        arr[i] = 0;
    for(int i = count_0; i < count_0 + count_1; i++)
        arr[i] = 1; 
    for(int i = count_0 + count_1; i<n; i++)
        arr[i] = 2;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n ; i++)
        cin>>arr[i];
    //segregate(arr, n);
    segregate1(arr, n);
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}