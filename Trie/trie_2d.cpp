#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3;
const int charset = 255;
int trie[maxn][charset];
int leaf[maxn];
int root = 0;
int sz = 1;

void insert(string s){
    int node = root;

    for(int i = 0; i<s.length(); i++){
        if(trie[node][s[i]] == -1)
            trie[node][s[i]] = sz++;
        
        node = trie[node][s[i]];
    }

    leaf[node]++;
}

bool search(string s){
    int node = root;

    for(int i =0; i<s.length(); i++){
        if(trie[node][s[i]] == -1)
            return false;
        node = trie[node][s[i]];
    }

    return leaf[node];
}

int main(){
    memset(trie, -1, sizeof(trie));
    string s[] = {"anurag", "kumar"};
    int n = sizeof(s) / sizeof(s[0]);
    for(int i = 0; i<n; i++)
        insert(s[i]);
    
    if(search("anurag"))
        cout<<"yes, it is found"<<endl;
    else 
        cout<<"no";
}