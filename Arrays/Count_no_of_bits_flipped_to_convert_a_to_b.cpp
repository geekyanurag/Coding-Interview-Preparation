#include<bits/stdc++.h>
using namespace std;

// input - 7 10 output - 3
// Idea is to take xor of a & b then count the number of set bits in xor of a & b.
int numFlipped(int a, int b){
    int x = a ^ b;
    int count = 0;
    
    for(int i =0; i<32; i++){
        if(x & (1 << i))
            count++;
    }
    return count;
}

int main(){
    int a, b;
    cin>>a>>b;
    int res = numFlipped(a, b);
    cout<<res<<endl;
}