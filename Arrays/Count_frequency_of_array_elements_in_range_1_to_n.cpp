#include<bits/stdc++.h>
using namespace std;

// To find the frequency of each element in the array and the array elements are in the range 1 to n.
// The idea is subtract 1 from all elements of array and then take array element as index and store the count ie arr[arr[i] % n] += n.
// Then arr[i] / n is the (i + 1)th frequency. To find the original element do arr[i] % n and add 1 to it. 
void freq(int arr[], int n){
    
    for(int i =0; i<n ;i++){
        arr[i] -= 1;
    }

    for(int i =0; i<n; i++){
        arr[arr[i] % n] += n;
    }
    for(int i = 0; i<n; i++){
        cout<<i + 1<<" "<<arr[i] / n<<endl;
    }
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    freq(arr, n);
    return 0;
}