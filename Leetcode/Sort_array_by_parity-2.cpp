class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int>v(A.size());
        int x = 0, y = 1;
        for(int i =0; i<A.size(); i++){
            if(A[i] & 1){
                v[y] = A[i];
                y += 2;
            }
            else{
                v[x] = A[i];
                x +=  2;
            }
        }
        return v;
    }
};