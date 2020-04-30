class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minm = 0, x = 0, res;
        for(int i =0; i<nums.size(); i++){
            x += nums[i];
            if(x <= 0){
                x = abs(x) + 1;
                minm += x;
                x = 1;
            }
        }
        if(minm == 0)
            minm = 1;
        return minm;
    }
};