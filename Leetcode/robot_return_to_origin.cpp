class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0 ;
        for(int i =0; i<moves.size(); i++){
            if(moves[i] == 'U')
                y++;
            if(moves[i] == 'D')
                y--;
            if(moves[i] == 'L')
                x--;
            if(moves[i] == 'R')
                x++;
        }
        if(x == 0 && y == 0)
            return true;
        else
            return false;
    }
};