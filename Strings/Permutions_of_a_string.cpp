#include<bits/stdc++.h>
using namespace std;

// Finding all permutation of the string
// 
void permutate(string s, int l, int r){
    if(l == r){
        cout<<s<<endl;
    }
    else{
    for(int i = l; i<= r; i++){
        swap(s[l], s[i]);       // Swapping
        permutate(s, l + 1, r); // Recursion called
        swap(s[l], s[i]);       // Backtrack
    }
    }
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    permutate(s, 0, n - 1);
    return 0;
}