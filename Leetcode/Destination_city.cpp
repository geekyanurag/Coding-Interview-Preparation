class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string out[paths.size()];
        string res;
        unordered_map<string,int>mp;
        for(int i =0; i<paths.size(); i++){
            mp[paths[i][0]]++;
            out[i] = paths[i][1];
        }
        for(int i = 0; i<paths.size(); i++){
            if(!mp.count(out[i]))
                res += out[i];
        }
        return res;
    }
};