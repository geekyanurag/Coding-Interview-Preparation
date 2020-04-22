#include<bits/stdc++.h>
using namespace std;

//finding nth ugly number. An ugly number is a number which is only divisible by 2, 3 or 5
int uglyNum(int n){
    int next_2, next_3, next_5, i2 = 0, i3 = 0, i5 = 0, m = 1;
    int ugly[n + 1];     //ugly will store the multiple of the numbers 2, 3, 5
    ugly[0] = 1;
    next_2 = ugly[i2] * 2;
    next_3 = ugly[i3] * 3;
    next_5 = ugly[i5] * 5;
    for(int i =1; i<n; i++){
        m = min(min(next_2, next_3), next_5);        // ex - min(2 * 1 , 3 * 1, 5 * 1) = 2 so now those who have 2 as multiple i2 += 1; 
        ugly[i] = m;
        if(m == next_2){
            i2 += 1;
            next_2 = ugly[i2] * 2;
        }
        if(m == next_3){
            i3 += 1;
            next_3 = ugly[i3] * 3;
        }
        if(m == next_5){
            i5 += 1;
            next_5 = ugly[i5] * 5;
        }
    }
    return m;
}
int main(){
    int n;
    cin>>n;
    cout<<uglyNum(n);
}