class Solution {
public:
    int f(int idx, int transaction, int canBuy, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(idx == prices.size()) {
            return 0;
        }
        if(transaction >= 2) return 0;
        if(dp[idx][canBuy][transaction] != -1) return dp[idx][canBuy][transaction];

        int profit = 0;
        if(canBuy) {
            // buying
            // taking the max of take and not take
            profit = max(
                -prices[idx] + f(idx+1, transaction, 0, prices, dp),
                f(idx+1, transaction, 1, prices, dp)
            );
        } else {
            // selling
            profit = max(
                prices[idx] + f(idx+1, transaction+1, 1, prices, dp),
                f(idx+1, transaction, 0, prices, dp)
            );
        }

        return dp[idx][canBuy][transaction] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0,0, 1, prices, dp);
        
    }
};