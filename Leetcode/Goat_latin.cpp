class Solution {
public:
    string toGoatLatin(string S) {
        string st, str;
        int count = 0;
        for(int i =0; i<S.length(); i++){
            st += S[i];
            if(isspace(S[i]) || i == S.length()-1){
                count++;
                if(i != S.length() - 1)
                    st.pop_back();
                char y;
                if(isupper(st[0]))
                    y = tolower(st[0]);
                else
                    y = st[0];
                if(y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u'){
                  str += st;
                str += "ma";
                for(int i =0; i<count; i++){
                    str += 'a';
                }  
                }
                else{
                char x = st[0];
                st.erase(st.begin(), st.begin() + 1);
                str += st;
                str += x;
                str += "ma";
                for(int i =0; i<count; i++)
                    str += 'a';
                }
                if(i != S.length() - 1)
                    str += " ";
                st.clear();
            }
        }
        return str;
    }
};