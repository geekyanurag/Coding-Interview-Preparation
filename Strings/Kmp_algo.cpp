#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void computeLps(int* lps, string pat){
    int n = pat.length();
    int j = 0, i = 1;
    lps[0] = 0;

    while(i < n){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string txt, string pat){
    int n = txt.length();
    int m = pat.length();
    int i = 0, j = 0;
    int lps[m];
    computeLps(lps, pat);
    while(i < n){
        if(txt[i] == pat[j]){
            i++, j++;
        }
        
        if(j == m){
            cout<<"Pattern found in index "<<i - j<<endl;
            j = lps[j-1];
        }
        else if(i < n && txt[i] != pat[j]){
            if(j != 0)
                j = lps[j-1];
            else{
                i += 1;
            }
        }
    }
}


int main(){
    string pat, txt;
    cin>>txt>>pat;
    kmp(txt, pat);
    return 0;
}