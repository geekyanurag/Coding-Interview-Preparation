// Problem is to find the index of the first occurence of string s which appears in string x.
int strstr(string s, string x)
{
     int n = s.length();
     int m = x.length();
     int res = -1;
     for(int i = 0; i<n-m+1; i++){
         int count = 0;
         for(int j = 0; j<m; j++){
             if(x[j] == s[i+j]){
                 count++;
             }
             else
                break;
         }
         if(count == m){
             res = i;
             break;
         }
     }
     return res;
}