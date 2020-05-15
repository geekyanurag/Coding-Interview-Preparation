// Problem is given two strings then find out whether each ith character have corresponding jth character in both string or not.
// e.g = s1 = aabcb and s2 = bbada , so here s1[0] = a and s2[0] = b and when s1[4] = b so s2[4] should be a.
bool areIsomorphic(string str1, string str2)
{
    bool res = true;
    char c[26], d[26];
    for(int i = 0; i<26; i++){
        c[i] = '0';
        d[i] = '0';
    }
    int i = 1, n1 = str1.length(), n2 = str2.length();
    if(n1 != n2)
        res = false;
    else {
        for(int i =0; i<n1; i++){
            if(c[str1[i] - 'a'] == '0' && d[str2[i] - 'a'] == '0'){
                c[str1[i] - 'a'] = str2[i];
                d[str2[i] - 'a'] = str1[i];
            }
            else{
                if(c[str1[i] - 'a'] != str2[i] || d[str2[i] - 'a'] != str1[i]){
                    res = false;
                    break;
                }
            }
        }
    }
    return res;
}