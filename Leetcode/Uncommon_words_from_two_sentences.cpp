class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int>mp;
        string s;
        vector<string>v;
        for(int i =0; i<A.length(); i++){
            s += A[i];
            if(isspace(A[i])){
                s.pop_back();
                mp[s]++;
                s.clear();
            }
        }
        mp[s]++;
        s.clear();
        for(int i =0; i<B.length(); i++){
            s += B[i];
            if(isspace(B[i])){
                s.pop_back();
                mp[s]++;
                s.clear();
            } 
        }
        mp[s]++;
        s.clear();
        for(auto i : mp){
            if(i.second == 1)
                v.push_back(i.first);
        }
        return v;
    }
};