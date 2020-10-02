#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Given strings with . in it we have to reverse each words in it.
// e.g. = string - i.like.this.program.very.much  output - much.very.program.this.like.i
// Solution is to reverse each word individually then reverse the whole array.
void solve(string s){
    int n = s.length(), x = 0, y = 0;       // x and y store the index of first and last element of string to be reversed.
    for(int i = 0; i<n; i++){
        if(s[i] == '.'){
            y = i - 1;
            while(x <= y)
                swap(s[x++],s[y--]);
            y = i;
            x = i + 1;
        }
    }
    y = n - 1;
    while(x <= y)
        swap(s[x++] , s[y--]);
    reverse(s.begin(), s.end());
    cout<<s<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        solve(s);
    }
    return 0;
}