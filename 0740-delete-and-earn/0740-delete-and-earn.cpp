class Solution {
public:
    int f(int i, vector<int>& sum, vector<int>& dp) {
        // base case
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];

        // recurrsion
        int pick = sum[i] + f(i-2, sum, dp);
        int notpick = 0 + f(i-1, sum, dp);

        return dp[i] = max(pick, notpick);

    }
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> sum(n+1, 0);
        vector<int> dp(n+1, 0);

        for(auto i : nums) {
            sum[i] +=  i;
        }

        dp[1] = sum[1];
        for(int i = 2; i<=n; i++) {
            int pick = sum[i] + dp[i-2];
            int notpick = 0 + dp[i-1];

            dp[i] = max(pick, notpick);
        }

        return dp[n];
    }
};