// O(n) - Complexity Solution (linear Search)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2);
        res[0] = -1;
        res[1] = -1;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
                res[0] = i;
                break;
            }
        }
        for(int i = n - 1; i>=0; i--){
            if(nums[i] == target){
                res[1] = i;
                break;
            }
        }
    
        return res;
    }
};

// O(logn) - complexity solution (binary search)
class Solution {
public:
    int search(vector<int>&nums, int target, bool left){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid] > target || (left && nums[mid] == target))
                r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res = {-1,-1};
        int first = search(nums, target, true);  // we are passing third variable because if it is true then it will check for first occurence of that element and if it is false search for last occuring element.
        
        if(first == nums.size() || nums[first] != target){
            return res;
        }
        res[0] = first;
        res[1] = search(nums, target, false) - 1;
        return res;
    }
};