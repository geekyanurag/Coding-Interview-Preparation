// Problem is to find the column name given the column number. e.g = n = 51 then string will be AY.
string ExcelColumn(int n)
{
    string s;
    while(n > 0){
    int r = n % 26;
    if(r == 0){
        s += 'Z';
        n = (n / 26) - 1;
    }
    else{
        s += (r - 1) + 'A';
        n = n / 26; 
    }
    }
    reverse(s.begin(), s.end());
    return s;
}