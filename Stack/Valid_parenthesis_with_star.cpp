#include<bits/stdc++.h>
using namespace std;

/* Problem is to find whether the given string is balanced or not given that * is also there which can be replaced by left or
right parenthesis.  */

// Using Stack - Extra Space 
/* The idea is to take two stack and when ( is there push that character's index in one stack and when * then push index to other stack. When ) encounters
then if ( stack is empty and if * is empty return false else pop from * stack and if ( is not empty pop from it. Now when all the ) is satisfied
then if ( is empty return true else ( is not empty then while top of * stack > top of ( stack and * stack is not empty then pop (.  If
* stack is empty return false then pop * and (. */

bool isBalanced(string s){
    stack<int>star, open;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(') open.push(i);
        else if(s[i] == '*') star.push(i);
        else{
            if(open.empty()){
                if(star.empty()) return false;
                else star.pop();
            }
            else{
                open.pop();
            }
        }
    }
    // Handle cases after all ) is finished.
    if(open.empty()) return true;
    else{
        if(star.empty()) return false;
        else{
            while(!star.empty() && !open.empty()){
                if(star.top() > open.top()){
                    star.pop();
                    open.pop();
                }
                else
                    break;
            }
        }
    }
    return open.empty();
}

// Without Stacks - In constant space
bool isvalid(string s){
    int l=0, r = 0;
    for(char c : s){
        if(c == '(') l++, r++;
        if(c == ')') l--, r--;
        if(c == '*') l--, r++;
        if(r < 0) return false;
        l = max(l, 0);
    }
    return l == 0;
}

int main(){
    string s;
    cin>>s;
    cout<<isBalanced(s)<<endl;
    cout<<isvalid(s)<<endl;
    return 0;
}