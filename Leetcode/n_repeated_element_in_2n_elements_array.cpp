class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n = A.size() >> 1;
        int res;
        unordered_map<int,int>mp;
        for(int i = 0; i<A.size(); i++){
            mp[A[i]]++;
        }
        for(auto i : mp){
            if(i.second == n)
                res = i.first;
        }
        return res;
    }
};