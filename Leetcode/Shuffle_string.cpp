class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char res[s.length()];
        for(int i = 0; i<s.length(); i++){
            res[indices[i]] = s[i];
        }
        string st;
        for(int i = 0; i<s.length(); i++)
            st += res[i];
        return st;
    }
};