// First solution is sort the nums vector in decreasing order then loop through it and check if current_sum > sum - current_sum then break;
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int>v;
        int sum = 0, current_sum = 0;
        for(int i =0; i<nums.size(); i++)
            sum += nums[i];
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i =0; i<nums.size(); i++){
            v.push_back(nums[i]);
            current_sum += nums[i];
            if(current_sum > sum - current_sum)
                break;
        }
        return v;
    }
};

// Otherwise use priority_queue 
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>p;
        vector<int>v;
        int sum = 0;
        for(int i =0; i<nums.size(); i++){
            p.push(nums[i]);
            sum += nums[i];
        }
        int y, q_sum = 0;
        while(!p.empty()){
            int x = p.top();
            q_sum += x;
            sum -= x;
            if(q_sum >= sum){
                y = x;
                break;
            }
            p.pop();
        }
        while(!p.empty()){
            v.push_back(p.top());
            p.pop();
        }
       sort(v.begin(), v.end(), greater<int>());
        return v;
    }
};