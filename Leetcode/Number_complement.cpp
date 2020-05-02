class Solution {
public:
    int findComplement(int num) {
        int i = 0, n = 0;
        while(num != 0){
            int r = num % 2;
            r = !r;
            n += pow(2, i) * r;
            num /= 2;
            i++;
        }
        return n;
    }
};