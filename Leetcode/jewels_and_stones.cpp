class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_map<char,int>mp;
        for(int i =0; i<S.length(); i++)
            mp[S[i]]++;
        for(int i = 0; i<J.length(); i++){
            if(mp[J[i]] > 0)
                count += mp[J[i]];
        }
        return count;
    }
};