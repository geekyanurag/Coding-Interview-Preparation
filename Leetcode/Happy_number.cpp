class Solution {
public:
    bool isHappy(int n) {
        int cnt = 100005, sum = 0;
        bool res = false;
        for(int i = 1; i<=cnt; i++){
            sum = 0;
            while(n != 0){
                int r = n % 10;
                sum += r*r;
                n = n / 10;
            }
            n = sum;
            if(n == 1){
                res = true;
                break;
            }
        }
        return res;
    }
};