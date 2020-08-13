// In this case the numbers can be repeating.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, k = 0;
        unordered_map<int,int>mp;
        vector<int>arr(r + 1);
        for(int i = 0; i<r+1; i++){
            if(mp.count(nums[i]) == 0){
                arr[k++] = nums[i];
                mp[nums[i]] += 1;
            }
        }
        int h = arr.size();
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] == target)
                return true;
            if(nums[l] < nums[mid]){
                if(target >= nums[l] && target <= nums[mid])
                        r = mid - 1;
                else l = mid + 1;
            }
            else if(nums[l] > nums[mid]){
                if(target >= nums[mid] && target <= nums[r])
                        l = mid + 1;
                else r = mid - 1;
            }
            else l++;     // this is to handle the case of duplicates if(nums[l] == nums[mid]) [if same number then l++].
        }
        return false;
    }
};