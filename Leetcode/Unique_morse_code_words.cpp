class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string, int>mp;
        for(int i =0; i<words.size(); i++){
            string x;
            for(int j = 0; j<words[i].length(); j++){
                x += v[words[i][j] - 'a'];
            }
            mp[x]++;
        }
        return mp.size();
        
    }
};