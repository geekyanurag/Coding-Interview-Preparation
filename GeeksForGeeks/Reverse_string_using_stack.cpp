// Problem is to reverse the given string using stack.
void reverse(char *str, int len)
{
    char *temp = str;
    string res, s;
    stack<char>st;
    while(*temp){
        st.push(*temp);
        *temp++;
    }
    while(*str){
        *str = st.top();
        *str++;
        st.pop();
    }
}