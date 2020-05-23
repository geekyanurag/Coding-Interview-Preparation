// Problem is to count the number of bits needed to flipped to change a to b. 
// Idea is to take the xor of a & b then count the number of set bits.
int countBitsFlip(int a, int b){
    
    int x = a ^ b, count = 0;
    while(x > 0){
        if(x & 1)
            count++;
        x >>= 1;
    }
    return count;
    
}