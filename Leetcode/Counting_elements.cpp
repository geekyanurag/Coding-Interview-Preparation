class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int>mp;
        int count = 0;
        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for(int i =0; i<arr.size(); i++){
            if(mp.find(arr[i] + 1) != mp.end())
                count += 1;
        }
        return count;
    }
};