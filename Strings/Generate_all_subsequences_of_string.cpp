#include<bits/stdc++.h>
using namespace std;

// Generate all Subsequences of a string. Total subsequences  = 2^n (for each character there is 2 option either take it or not then 2 * 2 * 2 ... 2 (upto n times) ie 2^n)
// we take two string input = "ab", output = "". Then we check if we have to take the first character or not ie. a if we do not take it
// then new input = b, output = "" but we take the first char then output will be "a" then recursively do it for new input.
void print(string input, string output){
    // Base case when input becomes empty
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    
    print(input.substr(1), output); // when we do not take the ith character in the output
    print(input.substr(1), output + input[0]); // when we take the ith character in the output
}
int main(){
    string input, output = "";
    cin>>input;
    print(input, output);
    return 0;
}