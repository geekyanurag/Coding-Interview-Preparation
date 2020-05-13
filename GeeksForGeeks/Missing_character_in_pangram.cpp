// Problem is to find the missing characters that will make the string a pangram.
// A pangram is that string which have all the letters in the alphabet.
string missingPanagram(string str){
    for(int i=0; i<str.length(); i++)
        str[i] = tolower(str[i]);
    map<char,int>m;
    for(int i =0; i<str.length(); i++){
        m[str[i]]++;
    }
    string s;
    for(char c = 'a'; c <= 'z'; c++){
        if(!m.count(c))
            s += c;
    }
    return s;
}