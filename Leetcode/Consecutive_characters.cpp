class Solution {
public:
    int maxPower(string s) {
        int count = 1, max_count = 1;
        for(int i =1; i<s.length(); i++){
            if(s[i] == s[i-1]){
                count += 1;
                max_count = max(count, max_count);
            }
            else
                count = 1;
        }
        return max_count;
    }
};