class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;
        for(int i = left; i<=right; i++){
            bool isnum = true;
            int x = i;
            while(x != 0){
                int r = x % 10;
                if(r == 0){
                    isnum = false;
                    break;
                }
                if(i % r != 0){
                    isnum = false;
                    break;
                }
                x /= 10;
            }
            if(isnum)
                res.push_back(i);
        }
        return res;
    }
};