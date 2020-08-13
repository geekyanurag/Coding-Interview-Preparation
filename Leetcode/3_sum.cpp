class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>count;
        set<vector<int>>s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(sum > 0)
                        r--;
                else l++;
            }
        }
        for(auto i : s){
            count.push_back(i);
        }
        return count;
    }
};