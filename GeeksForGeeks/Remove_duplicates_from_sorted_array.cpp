#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i =0; i<t; i++){
        int n, k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i =0; i<n ;i++)
            cin>>v[i];
        int minm = *min_element(v.begin(), v.end());
        if(minm > k)
            cout<<"0"<<endl;
        else
            cout<<abs(minm - k)<<endl;
    }
}