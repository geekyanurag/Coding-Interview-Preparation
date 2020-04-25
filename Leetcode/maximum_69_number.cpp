class Solution {
public:
    int maximum69Number (int num) {
        int pos = 0, last = 0, x = num;
        while(x > 0){
            int r = x % 10;
            pos++;
            if(r == 6)
                last = pos;
            x = x / 10;
        }
        if(last != 0){
            last -= 1;
            num += (3 * pow(10,last));
        }
        return num;
    }
};