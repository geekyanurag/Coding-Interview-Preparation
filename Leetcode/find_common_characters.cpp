// we use count array where it stores the count of characters in first element of the vector from a - z;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int count[26] = {0} ;
        string p = A[0] ;
        
        for(char c : p){
            count[c-'a']++ ;
        }
        for(string s : A){
            
            int dummy_count[26] = {0} ;
            for(char c : s){
                dummy_count[c-'a']++ ;
            }
            for(int i=0 ; i<26 ; i++){
                count[i] = min(count[i],dummy_count[i]) ;
            }
            
        }
        vector<string> res ;
        
        for( int i=0 ; i<26 ; i++ ){
            while(count[i]>0){
                auto k = char(i+'a') ;
                string p = "" ;
                p.push_back(k) ;
                res.push_back(p) ;
                count[i]-- ;
            }
        } 
        return res ;
    }
};

// Another solution is to use hashmap to store the characters
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string>v;
        unordered_map<char,int>mp;
        for(char c = 'a' ; c <= 'z'; c++)
            mp[c] = 0;
        for(auto i : A[0]){
            mp[i] ++;
        }
        for(int i =1; i<A.size(); i++){
            unordered_map<char,int>m;
            for(int j : A[i]){
                m[j]++;
            }
            for(char c = 'a'; c<='z'; c++){
                mp[c] = min(m[c], mp[c]);
            }
        }
        for(auto i = mp.begin(); i!=mp.end(); i++){
            for(int j = 0; j<i->second; j++){
                string x(1, i->first);
                v.push_back(x);
            }
        }
        return v;
    }
};