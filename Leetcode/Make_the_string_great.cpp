class Solution {
public:
    bool isUpper(char x){
        return (x >= 65  && x <= 90);
    }
    
    bool isLower(char x){
        return (x >= 97 && x <= 122);
    }
    string makeGood(string s) {
        string res;
        bool x = true;
        while(x){
            if(s == "")
                break;
            int count = 0, last = 0;
            for(int i = 0; i<s.length()-1; i++){
                if((isUpper(s[i]) && isLower(s[i + 1]) && (tolower(s[i]) == tolower(s[i + 1]))) || (isUpper(s[i + 1]) && isLower(s[i]) && (tolower(s[i]) == tolower(s[i + 1])))){
                    count++;
                    if(i == s.length() - 2)
                        last = 1;
                    i++;
                }
                else
                    res += s[i];
            }
            if(last == 0)
                res += s[s.length() - 1];
            s = res;
            if(count == 0)
                x = false;
            res.clear();
        }
        return s;
    }
};