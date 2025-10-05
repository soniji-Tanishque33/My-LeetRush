class Solution {
public:
    
    int mySqrt(int x) {
        if(x < 2) return x;

        int l = 1;
        int r = x/2;

        while(l <= r) {
            int mid = (l + r) / 2;
            long long sq = (long long) mid * mid;

            if(sq == x) return mid;
            if(sq < x) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return r;
    }
};