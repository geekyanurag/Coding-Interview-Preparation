class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(nums[i] == val)
                cnt++;
        }
        int l = 0, r = n-1;
        while(l <= r){
            if(nums[l] == val && nums[r] != val){
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++, r--;
            }
            else if(nums[l] != val && nums[r] != val) l++;
            else if(nums[l] == val && nums[r] == val) r--;
            else{
                l++, r--;
            }
        }
        return n - cnt;
    }
};