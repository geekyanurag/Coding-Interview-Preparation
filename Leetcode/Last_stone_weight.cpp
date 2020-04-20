class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(int i =0; i<stones.size(); i++)
            p.push(stones[i]);
        while(!p.empty()){
            if(p.size() == 1)
                break;
            int y = p.top();
            p.pop();
            int x = p.top();
            p.pop();
            int z = y - x;
            if(z != 0)
                p.push(z);
        }
        if(!p.empty())
            return p.top();
        else
            return 0;
    }
};