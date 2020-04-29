class Solution {
public:
    string reverseWords(string s) {
        string t, a;
        for(int i =0; i<s.length(); i++){
            a += s[i];
            if(isspace(s[i])){
                a.pop_back();
                reverse(a.begin(), a.end());
                t += a;
                t += " ";
                a.clear();
            }
            if(i == s.length() - 1){
                reverse(a.begin(), a.end());
                t += a;
            }
        }
        return t;
    }
};