#include<bits/stdc++.h>
using namespace std;

int main(){
    int res[200];
    res[0] = 1;
    int m = 1, n;
    cin>>n;
    for(int i = 2; i<=n; i++){
        int temp = 0;
        for(int j = 0; j<m; j++){
            int x = (res[j] * i) + temp;
            res[j] = x % 10;
            temp = x / 10;
        }
        while(temp > 0){
            res[m] = temp % 10;
            temp /= 10;
            m++;
        }
    }
    for(int i = m-1; i>=0; i--)
        cout<<res[i];
}