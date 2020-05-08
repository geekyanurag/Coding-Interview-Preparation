// Given n = size of array and k = size to reverse 
// e.g =  n = 1, 2, 3, 4, 5 and k = 3
// so ans = 3, 2, 1, 5, 4
vector<long long> reverseInGroups(vector<long long> mv, int n, int k){
    if(k >= n){
        reverse(mv.begin(), mv.end());
    }
    else{
        for(int i =0; i<n; i+=k){
            int left = i;
            int right = min(i + k -1, n - 1);
            while(left < right){
                long long temp = mv[left];
                mv[left] = mv[right];
                mv[right] = temp;
                left++; right--;
            }
        }
    }
    return mv;
}