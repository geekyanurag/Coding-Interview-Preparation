// check if number is power of 2 or not
bool isPowerofTwo(long long n){
    
    int res = 1;
    while(n > 1){
        if(n % 2 != 0){
            res = 0;
            break;
        }
        n >>= 1;
    }
    return res;
    
}