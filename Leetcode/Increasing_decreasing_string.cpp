class Solution {
public:
    string sortString(string s) {
        map<char,int>mp;
        string n;
        for(int i =0; i<s.length(); i++)
            mp[s[i]]++;
        while(n.length() != s.length()){
        for(auto i : mp){
            if(i.second > 0){
                n += i.first;
                mp[i.first]--;
            }
        }
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            if(it->second > 0){
                n += it->first;
                mp[it->first]--;
            }
        }
    }
       return n; 
    }
};