#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Problem is given a value k so we have to reverse k groups in array
// e.g = arr = {1, 2, 3, 4, 5} output = {3, 2, 1, 5, 4}
void reverse(int arr[], int n, int k){
    for(int i = 0; i<n; i += k){
        int left = i;
        
        int right = min(i + k - 1, n - 1);      // if right index crosses n then it will be n - 1
        
        while(left < right)
            swap(arr[left++], arr[right--]);    // Swap the k group elements
    }
    
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        reverse(arr, n, k);
    }
    return 0;
}