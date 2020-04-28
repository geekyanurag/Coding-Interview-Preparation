class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>v;
        sort(arr.begin(), arr.end());
        int minm = INT_MAX;
        for(int i =1; i<arr.size(); i++){
            minm = min(minm, abs(arr[i] - arr[i-1]));
        }
        for(int i = 1; i<arr.size(); i++){
            int x = arr[i] - arr[i-1];
            if(x == minm){
                v.push_back({arr[i-1], arr[i]});
            }
        }
        return v;
    }
};