// Problem is to find the bit which is different from right side of number in binary representation.
int posOfRightMostDiffBit(int m, int n)
{
    int x = m ^ n, count = 0;
    while(x > 0){
        count++;
        if(x & 1){
            break;
        }
        x >>= 1;
    }
    return count;
}