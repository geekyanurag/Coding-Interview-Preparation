#include<bits/stdc++.h>
using namespace std;

// Given a array of stocks you have to buy the stock and sell any number of times to maximize profit.
void solve(int arr[], int n){
    if(n == 1) cout<<"No Profit";

    int i = 0;
    while(i < n - 1){       // This is n - 1 because we are doing two operations that is buy and sell.

        while(i < n - 1 && arr[i+1] <= arr[i]) // Find the min value 
            i++;
        
        if(i == n - 1) break;       // If it is continuous decreasing

        int buy = i++;

        while(i < n && arr[i] >= arr[i - 1]) // Find the max value after chosen min value
            i++;
        
        int sell = i - 1;

        cout<<buy<<" "<<sell<<endl;
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    solve(arr, n);
    return 0;
}