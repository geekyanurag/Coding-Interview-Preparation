class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, r = 0, l = 0;
        for(int i =0; i<s.length(); i++){
            if(i == 0){
                if(s[i] == 'R')
                    r++;
                else 
                    l++;
            }
            else{
                s[i] == 'R' ? r++ : l++;
                if(r == l){
                    count += 1;
                    l = 0, r = 0;
                }
            }
        }
        return count;
    }
};