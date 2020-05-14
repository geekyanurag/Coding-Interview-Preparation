// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int x; long long l = 1, r = n;
        while(l <= r){
            long long mid = (l + r) / 2;
            if(!isBadVersion(mid - 1) && isBadVersion(mid)){
                x = mid;
                break;
            }
            if(isBadVersion(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return x;
    }
};