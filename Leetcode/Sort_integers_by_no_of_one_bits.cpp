class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i =0; i<arr.size(); i++){
            int x = __builtin_popcount(arr[i]);
            pq.push({x, arr[i]});
        }
        while(!pq.empty()){
            int a = pq.top().second;
            res.push_back(a);
            pq.pop();
        }
        return res;
    }

};