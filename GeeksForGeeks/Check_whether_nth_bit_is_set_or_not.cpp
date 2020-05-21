// use & operator with 1 << k.
bool checkKthBit(int n, int k){
    return (1 << k) & n;
}