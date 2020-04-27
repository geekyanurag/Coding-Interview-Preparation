class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        res = __builtin_popcount(res);
        return res;
    }
};