#include<bits/stdc++.h>
using namespace std;

// Using dp takes O(n * n) time and O(n*n) space.
int lps(string s){
    int n = s.length();
    int start = 0, max_len = 1;
    bool dp[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            dp[i][j] = 0;
    }
    
    for(int i = 0; i<n; i++){
        dp[i][i] = 1;
    }

    for(int i = 0; i<n-1; i++){
        if(s[i] == s[i + 1]){
            dp[i][i+1] = 1;
            if(start == 0)      // it will take the starting index of the first palindrome with length = 2
                start = i;
            max_len = 2;
        }
    }
    
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = (i + l) - 1;
        
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = 1;
                if(l > max_len){
                    max_len = l;
                    start = i;
                }
            }
        }
    }
    
    for(int i = start; i < start + max_len; i++)
        cout<<s[i];
}

// Another method
// This method use 2 pointer and take odd length and even length palindrome seperately, expanding the two pointers one to the left and another to the right to find the lps.
void lps2(string s){
    int max_len = 1, low, high, start = 0;
    int n = s.length();

    for(int i = 1; i<n; i++){
        low = i-1, high = i;        // For Even length
        while(low >=0 && high < n && s[low] == s[high]){
            if(high - low + 1 > max_len){
                start = low;
                max_len = high - low + 1;
            }
            low--, high++;
        }

        low = i-1, high = i + 1;    // For odd length
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