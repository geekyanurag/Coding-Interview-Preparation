// Problem is to find the equilibrium pt. which is a pt. whose left sum is equal to right sum excluding that pt.
int equilibriumPoint(long long a[], int n) {
    int left_sum = 0, sum = 0, idx = -1;
    for(int i = 0; i<n; i++)
        sum += a[i];
    for(int i = 0; i<n; i++){
        if(left_sum == sum - (left_sum + a[i])){
            idx = i + 1;
            break;
        }
        left_sum += a[i];
    }
    return idx;
}