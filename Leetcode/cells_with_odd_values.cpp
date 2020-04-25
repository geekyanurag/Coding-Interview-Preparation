class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int arr[n][m], count = 0;
        memset(arr, 0, sizeof(arr));
        for(int i =0; i<indices.size(); i++){
            int first = indices[i][0];
            int second = indices[i][1];
            for(int j = 0; j<m; j++)
                arr[first][j] += 1;
            for(int j = 0; j<n; j++)
                arr[j][second] += 1;
        }
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++)
                if(arr[i][j] & 1)
                    count++;
        }
        return count;
    }
};