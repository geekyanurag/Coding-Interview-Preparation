#include<bits/stdc++.h>
using namespace std;

// Idea is to take two loop first will be ith element and second will be jth element and take their sum and check if -ve of that num
// exists in the set or not (initially set is empty), if not exists insert the jth element in the set and repeat.
// we do not initially take the elements in set because by doing that we will have duplicates in the no. of triplets.
// time - O(n*n) and space - O(n)
void triplets(int arr[], int n){
    bool found = false;

    for(int i =0; i<n-1; i++){
        unordered_set<int>s;
        for(int j = i+1; j < n; j++){
            int sum = -(arr[i] + arr[j]);
            if(s.find(sum) != s.end()){
                cout<<"triplet found "<<sum<<" "<<arr[i]<<" "<<arr[j]<<endl;
                found = true;
            }
            else s.insert(arr[j]);
        }
    }

    if(!found) cout<<"No triplet found"<<endl;
}

// Another method is sorting. 
// Time - O(n*n), space - O(1)

void triplets1(int arr[], int n){
    bool found = false;
    sort(arr, arr + n);
    for(int i = 0; i<n-1; i++){
        int l = i + 1, r = n-1;
        while(l < r){
            if(arr[i] + arr[l] + arr[r] == 0){
                cout<<"triplets found "<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                l++, r--;
                found = true;
            }
            else if(arr[i] + arr[l] + arr[r] < 0)
                l++;
            else 
                r--;
        }
    }
    if(!found) cout<<"No triplets found"<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++)
        cin>>arr[i];
    //triplets(arr, n);
    triplets1(arr, n);
    return 0;
}