class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int res;
        for(int i =1; i<A.size()-1; i++){
            if(A[i] > A[i-1] && A[i] > A[i+1]){
                res = i;
                break;
            }
        }
        return res;
    }
};