class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>v(strs.size());
        unordered_map<string, vector<int>>mp;
        for(int i =0; i<strs.size(); i++){
            v[i] = strs[i];
            sort(v[i].begin(), v[i].end());
            mp[v[i]].push_back(i);
        }
        sort(v.begin(), v.end());
        vector<vector<string>>res(mp.size());
        int x = 0;
        for(int i = 0; i<v.size(); i++){
            if(i == 0){
                for(auto it = mp[v[i]].begin(); it!=mp[v[i]].end(); it++)
                    res[x].push_back(strs[*it]);
            }
            else{
                if(v[i] == v[i-1])
                    continue;
                else{
                    for(auto it = mp[v[i]].begin(); it!=mp[v[i]].end(); it++)
                    res[x].push_back(strs[*it]);
                }
            }
            x++;
        }
        return res;
    }
};