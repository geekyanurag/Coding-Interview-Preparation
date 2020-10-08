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

// Another method is to iterate in all possible subsequences so iterating till 2^n subsequences and check the set bits in that subsequence.
// If bit is set then print that character.
// e.g = string = "ab" so total size = 2 so all the possible subsequences are (00, 01, 10, 11) so all this binary representation where the bit is set print that character
// ie. take 10 so it will print b if 01 then print 1 and 11 then print ab.
/* Set  = [a,b,c]
power_set_size = pow(2, 3) = 8
Run for binary counter = 000 to 111

Value of Counter            Subset
    000                    -> Empty set
    001                    -> a
    010                    -> b
    011                    -> ab
    100                    -> c
    101                    -> ac
    110                    -> bc
    111                    -> abc
*/
void print1(string input){
    int n = s.length();
    for(int i = 1; i< (1<<n); i++){  // i is from 1 because we are not taking the empty subsequence.
        for(int j = 0; j<n; j++){
            if(i & (1 << j)) cout<<s[j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    string input, output = "";
    cin>>input;
    print(input, output);
    return 0;
}