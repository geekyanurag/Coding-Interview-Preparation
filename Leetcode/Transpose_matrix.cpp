class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>>res;
        vector<int>temp;
        for(int i =0; i<A[0].size(); i++){      // For m * n matrix we have to take the first loop for no. of columns ie n then inner loop for rows ie m.
            for(int j = 0; j < A.size(); j++)
                temp.push_back(A[j][i]);
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};