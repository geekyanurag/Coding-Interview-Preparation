// Count the number of set bits from 1 to n. eg. n = 4 so total number of set bits from 1 to 4.
int countSetBits(int n){
    
    int count = 0;
    for(int i =1; i<=n; i++){
        int x = __builtin_popcount(i);
        count += x;
    }
    return count;
    
    
}