class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        unordered_map<char,int>mp;
        int count = 0, line = 1;
        vector<int>v(2);
        for(int i =0; i<widths.size(); i++)
            mp[i + 'a'] = widths[i];
        for(int i =0; i < S.length(); i++){
            count += mp[S[i]];
            if(count > 100){
                line++;
                count = mp[S[i]];
            }
        }
        v[0] = line;
        v[1] = count;
        return v;
    }
};