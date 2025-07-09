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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int index = n-1; index >= 0; index--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                for(int transactions = k-1; transactions >=0; transactions--) {
                    // buying
                    int profit = 0;
                    if(canBuy) {
                        profit = max(
                            -prices[index] + dp[index+1][0][transactions],
                            dp[index+1][1][transactions]
                        );
                    } else {
                        // selling
                        profit = max(
                            prices[index] + dp[index+1][1][transactions+1],
                            dp[index+1][0][transactions]
                        );
                    }

                    dp[index][canBuy][transactions] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};