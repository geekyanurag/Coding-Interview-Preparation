class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int>mp;
        for(int i =0; i<emails.size(); i++){
            string s;
            int x = emails[i].find('@');
           // int y = emails[i].find('+');
            for(int j = 0; j<emails[i].length(); j++){
                if(emails[i][j] == '.')
                    continue;
                if(emails[i][j] == '+' || emails[i][j] == '@')
                    break;
                s += emails[i][j];
            }
            for(int k = x; k < emails[i].length(); k++)
                s += emails[i][k];
            mp[s]++;
        }
        int res = mp.size();
        return res;
    }
};