class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int>v(A.size());
        int k = 0, even_sum = 0;
        for(int i = 0; i<A.size(); i++){
            if(A[i] % 2 == 0)
                even_sum += A[i];
        }
        for(int i = 0; i<queries.size(); i++){
            int a = queries[i][0], b = queries[i][1];
            if(A[b] % 2 !=0){
                A[b] += a;
                if(A[b] % 2 == 0){
                    even_sum += A[b];
                }
                v[k] = even_sum;
                k++;
            }
            else{
                even_sum -= A[b];
                A[b] += a;
                if(A[b] % 2 == 0)
                    even_sum += A[b];
                v[k] = even_sum;
                k++;
            }
        }
        return v;
    }
};