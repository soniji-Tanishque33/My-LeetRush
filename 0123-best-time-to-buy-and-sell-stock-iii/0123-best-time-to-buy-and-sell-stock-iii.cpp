class Solution {
public:
    using vvvi = vector<vector<vector<int>>>;
    int f(int index, bool buy, int k, vector<int>& prices, vvvi& dp) {
        // base case
        if(k == 0) return 0;
        if(index == prices.size()) return 0;
        if(dp[index][buy][k] != -1) return dp[index][buy][k];

        // recurrsion
        int profit = INT_MIN;
        if(buy) {
            profit = max(
                -prices[index] + f(index+1, 0, k, prices, dp),
                0 + f(index+1, 1, k, prices, dp)
            );
        } else {
            profit = max(
                +prices[index] + f(index+1, 1, k-1, prices, dp),
                0+ f(index+1, 0, k, prices, dp)
            );
        }

        return dp[index][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};