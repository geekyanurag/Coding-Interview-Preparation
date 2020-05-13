// Problem is find the character which appears maximum time in string and if more than one character appears maximum times then print the 
// lexicographically the first one.
char getMaxOccuringChar(char* str)
{
    map<char,int>mp;
    char res;
    char *temp = str;
    while(*temp){
        mp[*temp]++;
        *temp++;
    }
    int maxn = 0;
    for(auto i : mp){
        if(i.second > maxn)
            maxn = i.second;
    }
    for(auto i : mp){
        if(i.second == maxn){
            res = i.first;
            break;
        }
    }
    return res;
}