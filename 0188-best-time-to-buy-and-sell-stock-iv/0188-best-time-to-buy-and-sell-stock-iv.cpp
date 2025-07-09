class Solution {
public:
    int f(int index, int k, bool canBuy, int transactions, vector<int>& prices, vector<vector<vector<int>>>& dp) {

        // base case
        if(index == prices.size()) {
            return 0;
        }
        if(transactions >= k) return 0;

        if(dp[index][canBuy][transactions] != -1) return dp[index][canBuy][transactions];


        // buying
        int profit = 0;
        if(canBuy) {
            profit = max(
                -prices[index] + f(index+1, k,  false, transactions, prices, dp),
                f(index+1, k, true, transactions, prices, dp)
            );
        } else {
            // selling
            profit = max(
                prices[index] + f(index+1, k, true, transactions+1, prices,dp),
                f(index+1, k, false, transactions, prices, dp)
            );
        }

        return dp[index][canBuy][transactions] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, -1)));
        return f(0, k, true, 0, prices, dp);
    }
};