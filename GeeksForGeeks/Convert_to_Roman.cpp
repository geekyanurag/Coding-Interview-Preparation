// Problem is given a number less than 5000 then convert the numeral into roman.
void convertToRoman(int n) 
{
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000,
     4000};
    string letter[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC",
                        "C", "CD", "D", "CM", "M", "VM"};
    int i = 13;
    string res;
    while(n > 0){
        int x = n / num[i];
        n = n % num[i];
        while(x --){
            res += letter[i];
        }
        i--;
    }
    cout<<res;
}