#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, count = 0;
    cin>>x;
    int y = x;
    while(y > 0){
        if(y & 1)
            count++;
        y >>= 1;
    }
    cout<<count;
}