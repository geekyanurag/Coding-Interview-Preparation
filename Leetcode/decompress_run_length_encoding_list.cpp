class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>v;
        for(int i =1; i<nums.size(); i+=2){
            int x = nums[i-1];
            for(int j = x; j>0; j--)
                v.push_back(nums[i]);
        }
        return v;
    }
};