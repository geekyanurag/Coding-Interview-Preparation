class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int sum = 0;
        for(auto i : mp){
            int x = i.second;
            sum += (x * (x - 1)) >> 1;
        }
        return sum;
    }
};