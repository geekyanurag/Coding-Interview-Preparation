class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(int i = 0; i<nums1.size(); i++)
            mp[nums1[i]] = 1;
        set<int>s;
        for(int i =0; i<nums2.size(); i++)
            s.insert(nums2[i]);
        for(auto i : s)
            if(mp[i])
                res.push_back(i);
        return res;
    }
};