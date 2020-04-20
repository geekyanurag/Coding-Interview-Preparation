class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        vector<int>v(prices.size()-1);
        for(int i =1; i<prices.size(); i++){
            v[i-1] = prices[i] - prices[i-1];
        }
        for(int i =0; i<v.size(); i++){
            if(v[i] > 0)
                sum += v[i];
        }
        return sum;
    }
};