#include<bits/stdc++.h>
using namespace std;

// Given (n - 1) integers and given integers have value in range 1 to n. So find the missing number.
// Method - 1 is to find the sum of all elements from 1 to n. So to calculate that use the sum formula ie. n * (n + 1) / 2. Here n is actually n + 1 since we have n - 1 integers.
// Then subtract all the elements from total. Then we get the missing element as total.
// Time complexity - O(n), Space complexity - O(1)
int missingNum(int arr[], int n){
    int total = ((n + 1) * (n + 2)) >> 1;

    for(int i =0; i<n; i++)
        total -= arr[i];
    
    return total;
}

// Method 2 is using XOR.
// The idea is first find the xor of all the elements in array(let xor1) then take another xor all the numbers from 1 to n+1 (let xor2) then take (xor1 ^ xor2).
// Time complexity - O(n), Space Complexity - O(1)
int missingNum2(int arr[], int n){
    int xor1 = arr[0], xor2 = 1;
    for(int i =1; i<n; i++)
        xor1 ^= arr[i];

    for(int i = 2; i<=n + 1; i++)
        xor2 ^= i;
    
    return xor1 ^ xor2;
}

// Method - 3 using boolean array
// This takes O(n) time and O(n) space
int missingNum3(int arr[], int n){
    int num;
    bool present[n + 1];
    for(int i =1; i<= n + 1; i++)
        present[i] = false;
    
    for(int i =0; i<n; i++){
        if(!present[arr[i]])
            present[arr[i]] = true;
    }

    for(int i =1; i<=n + 1; i++){
        if(!present[i]){
            num = i;
            break;
        }
    }
    return num;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    int res = missingNum(arr, n);
    int res2 = missingNum2(arr, n);
    int res3 = missingNum3(arr, n);
    cout<<res<<" "<<res2<<" "<<res3<<endl;
    return 0;
}