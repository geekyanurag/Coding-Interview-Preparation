// Problem is to check if a number is binary number is not. e.g - 101 is binary and 23 is not.
int isBinary(char *str)
{
    char *x = str;
    int y = 1;
    while(*x){
        int z = *x - '0';
        if(z != 0 && z!= 1){
            y = 0;
            break;
        }
        *x++;
    }
    return y;
}