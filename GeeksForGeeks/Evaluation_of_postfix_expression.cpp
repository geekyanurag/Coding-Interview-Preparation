// Given a postfix expression , evaluate the result of the expression. e.g = s = 23*5- return the ans.
int evaluatePostfix(string &str)
{
    stack<int>st;
    for(int i =0; i<str.length(); i++){
        if(st.empty()){
            st.push(str[i] - '0');
        }
        else{
            if(str[i] == '+'){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x + y);
            }
            else if(str[i] == '-'){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y - x);
            }
            else if(str[i] == '*'){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x * y);
            }
            else if(str[i] == '/'){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y / x);
            }
            else{
                st.push(str[i] - '0');
            }
        }
    }
    return st.top();
}