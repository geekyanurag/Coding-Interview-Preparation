class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), i = 0, res = 0;
        vector<int>last_idx (256, -1);
        for(int j = 0; j<n; j++){
            i = max(i, last_idx[s[j]] + 1);
            res = max(res, j - i + 1);
            last_idx[s[j]] = j;
        }
        return res;
    }
};