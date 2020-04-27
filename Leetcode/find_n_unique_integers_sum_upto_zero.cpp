class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>v;
        if(n & 1){
            for(int i = 0; i<= n/2; i++)
                v.push_back(i);
            int x = -(n/2);
            while(x != 0){
                v.push_back(x);
                x++;
            }
        }
        else{
            for(int i = 1; i<= n/2; i++)
                v.push_back(i);
            int x = -(n/2);
            while(x != 0){
                v.push_back(x);
                x++;
            }
        }
        return v;
    }
};