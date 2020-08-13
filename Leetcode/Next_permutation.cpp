class Solution {
public:
    void swap(vector<int>&arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    void reverse(vector<int>&nums, int l, int r){
        while(l <= r){
            swap(nums, l, r);
            l++, r--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >=0 && nums[i] >= nums[i + 1]) i--;
        
        if(i < 0){
            reverse(nums, i + 1, nums.size() - 1);
        }
        else{
            int j = i + 1;
            while(j < nums.size() && nums[i] < nums[j]) j++;
            swap(nums, i, j - 1);
            reverse(nums, i + 1, nums.size() - 1);
        }
    }
};