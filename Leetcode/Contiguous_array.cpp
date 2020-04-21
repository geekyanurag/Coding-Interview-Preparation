class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == 0)
                nums[i] = -1;
        }
        unordered_map<int,int>mp;
        int max_sum = 0,sum = 0, len = 0;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            if(sum == 0){
                len = i + 1;
                max_sum = max(max_sum, len);
            }
            else{
                if(mp.find(sum) != mp.end())
                    max_sum = max(max_sum, i - mp[sum]);
                else{
                    mp[sum] = i;
                }
            }
        }
        return max_sum;
    }
};