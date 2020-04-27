class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int>res (S.length() + 1);
        int a = 0, j = S.length();
        for(int i =0; i<S.length(); i++){
            if(S[i] == 'I'){
                res[i] = a;
                a++;
            }
            if(S[i] == 'D'){
                res[i] = j;
                j--;
            }
        }
        res[S.length()] = j;
        return res;
    }
};