class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> dp(n+1, 0);
        int sub = 1;

        for(int i = 1; i<=n; i++) {
            if(2*sub == i) {
                sub = i;
            }

            dp[i] = dp[i-sub] + 1;
        }

        return dp;
    }
};