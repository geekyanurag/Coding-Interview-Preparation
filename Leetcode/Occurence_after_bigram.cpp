class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string>t, res;
        string x;
        for(int i =0; i<text.length(); i++){
            x += text[i];
            if(isspace(text[i]) || i == text.length() - 1){
                if(i == text.length() - 1){
                    t.push_back(x);
                }
                else{
                    x.pop_back();
                    t.push_back(x);
                    x.clear();
                }
            }
        }
        for(int i = 0; i<t.size() - 2; i++){
            if(t[i] == first && t[i+1] == second){
                res.push_back(t[i+2]);
            }
        }
        return res;
    }
};