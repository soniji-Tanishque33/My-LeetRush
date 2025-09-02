class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int nn = n;

        while(nn > 1) {
            if(nn % 2 == 1) return false;
            nn /= 2;
        }
        return true;
    }
};