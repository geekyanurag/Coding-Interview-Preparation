#include<bits/stdc++.h>
using namespace std;

// Method - 1 take a loop till n becomes 0 where divide n by 10 and increment count
int countingDigits(int n){
    int count = 0;
    while(n > 0){
        n = n / 10;
        count++;
    }
    return count;
}
// Method - 2 if n is the num and k is number of digits of n. Now n lies between pow(10, k-1)<= n < pow(10, k). Now take log base 10 both sides.
// It becomes k-1 <= log10(n) < k then add 1 both sides k <= log10(n) + 1 < k + 1 . So k = floor(log10(n)) + 1;
int countingDigits1(int n){
    int count = floor(log10(n) + 1);
    return count;
}

int main(){
    int n;
    cin>>n;
    int res = countingDigits(n);
    int res1 = countingDigits1(n);
    cout<<res<<" "<<res1<<endl;
}