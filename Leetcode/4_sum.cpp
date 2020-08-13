class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        set<vector<int>>s;
        vector<vector<int>>res;
        for(int i = 0; i<n-1; i++){
            for(int j = i + 1; j<n; j++){
                int l = j + 1, r = n - 1;
                while(l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target){
                        s.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                    }
                    else if(sum > target) r--;
                    else l++;
                }
            }
        }
        for(auto i : s)
            res.push_back(i);
        return res;
    }
};