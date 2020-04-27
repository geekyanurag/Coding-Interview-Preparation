class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>res;
    int rows = matrix.size();
    int cols = matrix[0].size();
    unordered_map<int, int>mp;
    int y = 0;
    for(int i =0; i<cols; i++){
        int z = matrix[0][i];
        for(int j = 0; j<rows; j++){
            z = max(matrix[j][i], z);
        }
        mp[i] += z;
    }
    for(int i = 0; i<rows; i++){
        int x = *min_element(matrix[i].begin(), matrix[i].end());
        int a; 
        for(int j =0; j<cols; j++){
            a = mp[j];
            if(x == a)
                res.push_back(x);
        }   
    }
        return res;
    }
};