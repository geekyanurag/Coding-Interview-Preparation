class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans;
        int diff = INT_MAX;
        for(int i = 0; i<n; i++){
            int l = i + 1, r = n-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(target - sum) < abs(diff)){
                    diff = target - sum;
                    ans = sum; 
                }
                else if(sum > target) r--;
                else l++;
            }
        }
        return ans;
    }
};