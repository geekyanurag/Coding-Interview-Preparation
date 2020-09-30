#include<bits/stdc++.h>
using namespace std;

// Using dp takes O(n * n) time and O(n*n) space.
void lps(string s){
    int n = s.length(), res = 1, start;
    bool dp[n + 1][n + 1];

    for(int i = 0; i<=n; i++) dp[i][0] = false;
    for(int j = 0; j<=n; )
    for(int i =0; i<n; i++)
        dp[i][i] = 1;
    
    int j;
    for(int l = 2; l<=n; l++){
        for(int i = 0; i<=n-l; i++){
            j = i + l - 1;
            if(l == 2){
                dp[i][j] = (s[i] == s[j]);
                start = i;
                res = 2;
            }
            else {
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                if(l > res) res = l, start = i;
            }
        }
    }
    for(int i = start; i < start + res; i++)
        cout<<s[i];
    cout<<endl;
    cout<<"And the length of the longest palindromic substring is "<<res<<endl;

}

// Another method
// This method use 2 pointer and take odd length and even length palindrome seperately, expanding the two pointers one to the left and another to the right to find the lps.
void lps2(string s){
    int max_len = 1, low, high, start = 0;
    int n = s.length();

    for(int i = 1; i<n; i++){
        low = i-1, high = i;
        while(low >=0 && high < n && s[low] == s[high]){
            if(high - low + 1 > max_len){
                start = low;
                max_len = high - low + 1;
            }
            low--, high++;
        }

        low = i-1, high = i + 1;
        while(low >=0 && high < n && s[low] == s[high]){
            if(high - low + 1 > max_len){
                start = low;
                max_len = high - low + 1;
            }
            low--, high++;
        }
    }
    cout<<s.substr(start, max_len);
}

int main(){
    string s;
    cin>>s;
    //lps(s);
    lps2(s);
    return 0;
}