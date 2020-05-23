// Problem is to find the first set bit of a number from right side of a number in a binary representation.
unsigned int getFirstSetBit(int n){
    
    int count = 0;
    while(n > 0){
        count++;
        if(n & 1){
            break;
        }
        n >>= 1;
    }
    return count;
}