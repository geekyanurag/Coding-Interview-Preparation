#include<bits/stdc++.h>
using namespace std;

// Optimized Solution
// Time complexity - O(max(square(arr[i]))), Space complexity - O(max(arr[i]))
// Problem is to check if there is a triplet which satisfies the pythagoras theorem ie (a * a) + (b * b) = (c * c)
// e.g = arr = {3, 2, 4, 6, 5} output = true
bool triplet(int arr[], int n){
    int maxn = -1;
    for(int i =0; i<n; i++)
        maxn = max(arr[i], maxn);           // Finding the maximum element in the array
    
    int hash[maxn + 1] = {0};               // Size of hash is equal to the value of max element + 1
    for(int i = 0; i<n; i++)                // Count the no. of times element occurs.
        hash[arr[i]]++;
    
    for(int i = 1; i < maxn + 1; i++){      // Iterating over all a's
        if(hash[i] == 0) continue;          // if a is not present then continue

        for(int j = 1; j < maxn + 1; j++){  // Iterate over all b's
            
            if((i == j && hash[i] == 1) || hash[j] == 0) continue;      // If a is equal to b but it appears only once or b is present then continue

            int val = sqrt((i * i) + (j * j));              // finding the value c
            if((val * val) != ((i * i) + (j * j))) continue;

            if(val > maxn) continue;        // if val is greater than the maximum element then continue

            if(hash[val]) return true;      // if val is present in array then return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    bool res = triplet(arr, n);
    cout<<res<<endl;
    return 0;
}