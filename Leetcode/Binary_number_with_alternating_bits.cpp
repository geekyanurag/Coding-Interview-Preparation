class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool res = true;
        int x = n;
        res = x & 1;
        x >>= 1;
        while(x > 0){
            if(res == (x & 1)){
                res = false;
                break;
            }
            res = !res;
            x >>= 1;
        }
        if(x == 0)
            res = true;
        return res;
    }
};