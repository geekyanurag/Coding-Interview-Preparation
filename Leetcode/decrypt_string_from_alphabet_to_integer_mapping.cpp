class Solution {
public:
    string freqAlphabets(string s) {
        string n;
        int i = 0;
        while(i < s.length()-2){
            int x;
            if(s[i + 2] == '#'){
                x = (10 * (s[i] - '0')) + (s[i+1] - '0');
                x = x + 'a' -1;
                n += char(x);
                i += 3;
            }
            else{
                x = (s[i] - '0') + 'a' - 1;
                n += x;
                i++;
            }
        }
        for(int j =i; j < s.length(); j++){
            int x = (s[j] - '0') + 'a' - 1;
            n += char(x);
        }
        return n;
    }
};