// Problem is to reverse each words in a string seperated by '.' e.g - "this.is.anurag" ans = "anurag.is.this"
void reverseWords(char *s) {
    char* temp = s;
    string st, x, res;
    while(*temp){
        st += *temp;
        *temp++;
    }
    for(int i = st.length() - 1; i>=0; i--){
        if(st[i] == '.'){
            reverse(x.begin(), x.end());
            x += st[i];
            res += x;
            x.clear();
        }
        else{
            x += st[i];
        }
    }
    reverse(x.begin(), x.end());
    res += x;
    cout<<res;
}