class Solution {
public:
    bool isPrime(int n){
        bool flag = 1;
        if(n == 1)
            flag = 0;
        else{
        for(int i =2; i*i<=n; i++){
            if(n % i == 0){
                flag = 0;
                break;
            }
            }
        }
        return flag;
    }
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for(int i = L; i<=R; i++){
            int x = __builtin_popcount(i);
            if(isPrime(x))
                count++;
        }
        return count;
    }
};