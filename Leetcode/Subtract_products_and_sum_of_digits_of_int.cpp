class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0, res = 0, x;
        while(n != 0){
            x = n % 10;
            prod *= x;
            sum += x;
            n = n / 10;
        }
        res = prod - sum;
        return res;
    }
};