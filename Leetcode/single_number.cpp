class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res;
        unordered_map<int,int>mp;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto i = mp.begin(); i!=mp.end(); i++){
            if(i->second == 1){
                res = i->first;
                break;
            }
        }
        return res;
    }
};