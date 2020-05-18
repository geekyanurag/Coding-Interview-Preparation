class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count = 0;
        unordered_map<char,int>mp;
        for(int i =0; i<text.length(); i++){
            if(text[i] == 'n' || text[i] == 'o' || text[i] == 'l' || text[i] == 'a' || 
              text[i] == 'b')
                mp[text[i]]++;
        }
        for(auto i : mp){
            if(i.first == 'l' || i.first == 'o'){
                mp[i.first] /= 2;
            }
        }
        if(mp.size() == 5){
            count = mp['b'];
            for(auto i : mp)
                count = min(count, i.second);
        }
        return count;
    }
};