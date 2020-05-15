#include<bits/stdc++.h>
#define chars 256
using namespace std;

// Idea is to store the last index of the characters being already visited.
int longestSubstr(string s){
    int n = s.length();
    int res = 0;
    vector<int> last_idx (chars, -1);
    int i = 0;
    for(int j =0; j<n; j++){
        i = max(i, last_idx[s[j]] + 1);
        res = max(res, j - i + 1);
        last_idx[s[j]] = j;
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    int result = longestSubstr(s);
    cout<<result<<endl;
    return 0;
}