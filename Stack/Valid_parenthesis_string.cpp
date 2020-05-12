#include<bits/stdc++.h>
using namespace std;

// Using stack extra space
bool isBalanced(string s){
    stack<char>st;
    for(char c : s){
        if(c == '(')
            st.push(c);
        else{
            if(s.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

// Using constant space
bool isBalanced1(string s){
    int l = 0;
    for(char c : s){
        if(c == '(')
            l++;
        else l--;
        if(l < 0) return false;
    }
    return l == 0;
}

int main(){
    string s;
    cin>>s;
    cout<<isBalanced(s)<<endl;
    cout<<isBalanced1(s)<<endl;
    return 0;
}