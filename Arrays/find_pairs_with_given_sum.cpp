#include<bits/stdc++.h>
using namespace std;

// Using hashmap time - O(n), space - O(n)
// Idea is to store all the elements with their count and loop till n and find if sum - arr[i] is present in map if yes then count
// will add with the no. of times the sum - arr[i] appears in map. And we return half of the count because a pair will be count twice.
// eg. = (1, 2) when we at 1 then we take 2 and count++ but when we are at 2 then also we take 1 and count++.
int findPairs(int arr[], int n, int sum){
    unordered_map<int,int>mp;
    int count_pairs = 0;

    for(int i = 0; i<n; i++){
        mp[arr[i]]++;
    }

    for(int i =0; i<n; i++){
        int num = sum - arr[i];
        if(mp.find(num) != mp.end()){
            count_pairs += mp[num];
        }
        // If the sum - arr[i] will be same as arr[i] we do not take it as a pair.
        if(num == arr[i]) count_pairs--;
    }
    return count_pairs / 2;
}

int main(){
    int n, sum;
    cin>>n>>sum;
    int *arr = new int[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    int res = findPairs(arr, n, sum);
    cout<<res<<endl;
    return 0;
}