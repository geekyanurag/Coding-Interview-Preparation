#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Problem is to check if two strings match if first string is rotated clockwise or anticlockwise to 2 places.
bool check(string u, string t){
    string s = u;
    int n = s.length();
    int x, y, k;
    k = 1;
    x = 0, y = k;
    while(x <= y)
        swap(s[x++], s[y--]);
    x = k + 1, y = n - 1;
    while(x <= y)
        swap(s[x++], s[y--]);
    reverse(s.begin(), s.end());
    
    if(s == t) return 1;
    
    s = u;
    k = n - 2;
    x = 0, y = k - 1;
    while(x <= y) swap(s[x++], s[y--]);
    x = k, y = n - 1;
    while(x <= y) swap(s[x++], s[y--]);
    reverse(s.begin(), s.end());
    
    if(s == t) return 1;
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s, t;
        cin>>s>>t;
        cout<<check(s, t);
        cout<<endl;
    }
    return 0;
}