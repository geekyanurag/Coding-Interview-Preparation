// To determine whether a two strings are anagram or not. An anagram is if two strings have same characters and also their frequency is same.
bool isAnagram(string c, string d){
    unordered_map<char,int>mp, m;
    int count = 1;
    bool res = 1;
    for(char x : c)
        mp[x]++;
    for(char x : d)
        m[x]++;
    set<char>s;
    for(char x : c)
        s.insert(x);
    for(char x : s){
        if(mp[x] == m[x]){
            continue;
        }
        else{
            count = 0;
            break;
        }
    }
    return count && mp.size() == m.size() ? 1 : 0;
}