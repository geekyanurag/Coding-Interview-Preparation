class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        queue<int>q;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] != 0)
                q.push(nums[i]);
        }
        while(i <=j){
            if(nums[i] == 0 && nums[j] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
            else if(nums[j] == 0 && nums[i] != 0){
                j --;
            }
            else if(nums[i] == 0 && nums[j] == 0) {
                j--;
            }
            else{
                i++;
            }
        }
        int y = 0;
        while(!q.empty()){
            nums[y] = q.front();
            q.pop();
            y ++;
        }
    }
};