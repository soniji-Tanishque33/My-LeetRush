class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        long nn = x;
        if (nn < 0) nn = -1*nn;

        while(nn>0){
            ans = ans * 10 + nn%10;
            nn = nn/10;
        }

        if(ans > INT_MAX || ans < INT_MIN) return 0;
        if (x < 0) return -1*(int)ans;
        return (int)ans;
    }
};