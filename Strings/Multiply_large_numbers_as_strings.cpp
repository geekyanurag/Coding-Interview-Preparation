#include<bits/stdc++.h>
using namespace std;

string multiply(string s1, string s2){
// Sign of s1 and s2 can be negative so to handle this the following lines of code.
    string a = s1, b = s2;
    if(s1.at(0) == '-' && s2.at(0) == '-'){
        s1 = s1.substr(1);
        s2 = s2.substr(1);
    }
    if(s1.at(0) == '-' && s2.at(0) != '-')
        s1 = s1.substr(1);
    else if(s1.at(0) != '-' && s2.at(0) == '-')
        s2 = s2.substr(1);

    int len1 = s1.length();
    int len2 = s2.length();

    if(len1 == 0 || len2 == 0)
        return "0";

    vector<int>res(len1 + len2, 0);
    int idx_s1 = 0, idx_s2 = 0;
    for(int i = len1-1; i>=0; i--){
        int carry = 0, n1 = s1[i] - '0';
        idx_s2 = 0;
        for(int j = len2 - 1; j >= 0; j--){
            int n2 = s2[j] - '0';
            int sum = (n1 * n2) + res[idx_s1 + idx_s2] + carry;
            res[idx_s1 + idx_s2] = sum % 10;
            carry = sum / 10;
            idx_s2++;
        }

        if(carry > 0)
            res[idx_s1 + idx_s2] += carry;
        idx_s1++;
    }

    int z = res.size() - 1;
    while(z >= 0 && res[z] == 0)
        z--;
    
    if(z == -1)
        return "0";
    string s;
    while(z >= 0)
        s += to_string(res[z--]);
    
    while(z >= 0)
        s += to_string(res[z--]);
    // Sign handling
    if((a.at(0) == '-' && b.at(0) != '-' ) || (a.at(0) != '-' && b.at(0) == '-' ))
        cout<<"-";

    return s;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    string res = multiply(s1, s2);
    cout<<res<<endl;
}