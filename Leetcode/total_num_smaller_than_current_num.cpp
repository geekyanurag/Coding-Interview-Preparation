class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int>mp;
        int length = nums.size();
        vector<int>ans(length);
        for(int i =0; i<nums.size(); i++)
            mp[nums[i]]++;
        for(int i =0; i<nums.size(); i++){
            int count = 0;
            for(auto it = mp.begin(); it!= mp.end(); it++){
                if(it->first < nums[i])
                    count += it->second;
            }
            ans[i] = count;
        }
        return ans;
    }
};