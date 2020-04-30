class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>res(S.length());
        int z = count(S.begin(), S.end(), C);
        vector<int>ch(z);
        int a = 0;
        for(int i =0; i<S.length(); i++){
            if(S[i] == C){
                ch[a] = i;
                a++;
            }
        }
        for(int i : ch)
            cout<<i<<" ";
        for(int i =0; i<S.length(); i++){
            int minm = INT_MAX;
            for(int j = 0; j<ch.size(); j++){
                minm = min(abs(ch[j] - i), minm);
            }
            res[i] = minm;
        }
        return res;
    }
};