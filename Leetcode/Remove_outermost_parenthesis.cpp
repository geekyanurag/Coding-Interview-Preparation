class Solution {
public:
    string removeOuterParentheses(string S) {
        string n;
        stack<char>st;
        for(int i =0; i<S.length(); i++){
            if(st.empty() && S[i] == '(')
                st.push(S[i]);
            else{
                if(S[i] == '('){
                    st.push(S[i]);
                    n += S[i];
                }
                if(S[i] == ')'){
                    n += S[i];
                    st.pop();
                }
                if(st.empty())
                    n.pop_abc
            }
        }
        return n;
    }
};