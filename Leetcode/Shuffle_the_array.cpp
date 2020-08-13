class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>res(2 * n);
        int x = n, y = 0;
        for(int i = 0; i<2 * n; i++){
            if(i & 1){
                res[i] = nums[x++];
            }
            else res[i] = nums[y++];
        }
        return res;
    }
};