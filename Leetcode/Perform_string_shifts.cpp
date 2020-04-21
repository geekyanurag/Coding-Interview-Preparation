class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = shift.size();
        for(int i =0; i<n; i++){
            int k = shift[i][1];
            int dir = shift[i][0];
            if(dir == 0){
                reverse(s.begin(), s.begin() + k);
                reverse(s.begin() + k, s.end());
                reverse(s.begin(), s.end());
            }
            else{
                reverse(s.rbegin(), s.rbegin() + k);
                reverse(s.rbegin() + k, s.rend());
                reverse(s.begin(), s.end());
            }
        }
        return s;
    }
};