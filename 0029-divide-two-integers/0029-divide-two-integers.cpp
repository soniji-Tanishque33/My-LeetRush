class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -1*dividend;
        bool neg = (dividend > 0) ^ (divisor > 0);

        long long divi = abs((long long) dividend);
        long long div = abs((long long) divisor);

        if(divi ==  div) {
            if(neg) return -1;
            return 1;
        }
        if(divi < div) return 0;
        long long ans = 0;

        while(divi >= div) {
            long long tmp = div;
            long long cnt = 1;

            while(divi >= tmp << 1) {
                // tmp = tmp * 2;
                tmp <<= 1;
                cnt <<= 1;
            }

            divi -= tmp;
            ans += cnt;

        }

        if(neg) return -1 * ans;
        return ans;


    }
};