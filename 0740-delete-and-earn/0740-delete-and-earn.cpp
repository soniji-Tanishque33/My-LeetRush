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
        for(auto i : nums) {
            sum[i] +=  i;
        }

        int prev2 = 0;
        int prev1 = sum[1];
        int curr = 0;
        for(int i = 2; i<=n; i++) {
            int pick = sum[i] + prev2;
            int notpick = 0 + prev1;

            curr = max(pick, notpick);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};