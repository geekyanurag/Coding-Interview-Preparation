class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int x = *max_element(A.begin(), A.end());
        int y = *min_element(A.begin(), A.end());
        int res;
        if(x <= K)
            res = 0;
        else{
            int z = x - K;
            if(z - y <= K)
                res = 0;
            else{
                int i = y + K;
                res = z - i;
            }
        }
        return res;
    }
};