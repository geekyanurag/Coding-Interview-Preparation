class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>res(nums1.size());
        for(int i =0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        for(int i = 0; i<nums1.size(); i++){
            int x = mp[nums1[i]];
            int max = -1;
            for(int j = x + 1; j < nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    max = nums2[j];
                    break;
                }
            }
            res[i] = max;
        }
        return res;
    }
};