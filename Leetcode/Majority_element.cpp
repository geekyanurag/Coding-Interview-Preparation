class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int res;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int x = nums.size() / 2;
        for(auto i : mp){
            if(i.second > x){
                res = i.first;
            }
        }
        return res;
    }
};