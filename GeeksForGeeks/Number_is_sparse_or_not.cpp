// Problem is to find the number is sparse or not. A sparse number is a number where there no consecutive set bits.
bool isSparse(int n){
    int count = 0, flag = 0, res = 1;
    int x = n;
    while(x > 0){
        int y = x & 1;
        if(y == 1)
            flag++;
        else
            flag = 0;
        if(flag > 1){
            res = 0;
            break;
        }
        x >>= 1;
    }
    return res;
}