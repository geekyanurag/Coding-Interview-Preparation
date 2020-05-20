class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>res;
        string x = "qwertyuiop", y = "asdfghjkl", z = "zxcvbnm";
        for(int i =0; i<words.size(); i++){
            int count_1 = 0, count_2 = 0, count_3 = 0;
            for(int j = 0; j<words[i].length(); j++){
                if(x.find(tolower(words[i][j])) != string::npos){
                    count_1++;
                }
            }
            for(int j = 0; j<words[i].length(); j++){
                if(y.find(tolower(words[i][j])) != string::npos){
                    count_2++;
                }
            }
            for(int j = 0; j<words[i].length(); j++){
                if(z.find(tolower(words[i][j])) != string::npos){
                    count_3++;
                }
            }
            if(count_1 == words[i].length() || count_2 == words[i].length() || count_3 == words[i].length()){
                //words[i][0] = toupper(words[i][0]);
                res.push_back(words[i]);
            }
        }
        return res;
    }
};