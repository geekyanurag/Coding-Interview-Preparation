class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s_new, t_new;
        for(int i =0; i<S.length(); i++){
            if(S[i] == '#' && s_new.length() != 0)
                s_new.pop_back();
            else{
                if(S[i] == '#')
                    continue;
                else
                    s_new += S[i];
             }
        }
        for(int i =0; i<T.length(); i++){
            if(T[i] == '#' && t_new.length() != 0)
                t_new.pop_back();
            else{
                if(T[i] == '#')
                    continue;
                else
                    t_new += T[i];
             }
        }
        if(s_new == t_new)
            return true;
        else 
            return false;
    }
};