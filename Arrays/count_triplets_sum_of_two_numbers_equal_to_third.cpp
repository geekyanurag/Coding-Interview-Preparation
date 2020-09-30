#include<bits/stdc++.h>
using namespace std;

int countTriplet(int arr[], int n)
	{
	    unordered_map<int,int>mp;
	    int count = 0;
	    if(n <= 2)
	        return 0;
	    for(int i = 0; i<n; i++)
	        mp[arr[i]]++;
	    for(int i = 0; i<n; i++){
	        for(int j = i + 1; j<n; j++){
	            if(mp[arr[i] + arr[j]]) count++;
	        }
	    }
	    return count;
	}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ;i++)
        cin>>arr[i];
    int res = countTriplet(arr, n);
    cout<<res<<endl;
}