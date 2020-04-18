class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxn = nums[0];
        int sum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            sum = max(nums[i], sum+nums[i]);
            maxn = max(maxn, sum);
        }
        return maxn;
    }
};