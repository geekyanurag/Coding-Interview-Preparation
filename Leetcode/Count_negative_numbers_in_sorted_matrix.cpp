class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(auto j : grid[i]){
                if(j < 0)
                    count++;
            }
        }
        return count;
    }
};