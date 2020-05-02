class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<pair<int,int>>s;
        unordered_map<int,int>mp;
        for(int i =0; i<candies.size(); i++){
            mp[candies[i]]++;
        }
        for(auto i : mp){
            s.insert({i.second, i.first});
        }
        int x = candies.size() >> 1, y = 0;
        for(auto i : s){
            y += 1;
            if(y == x)
                break;
        }
        return y;
    }
};