class Solution {
public: 
    bool f(int ind, int prev, vector<int>& stones, vector<vector<int>>& dp) {
        // base case

        if(ind == stones.size()-1) return true; 
        if(dp[ind][prev] != -1) return dp[ind][prev];

        // recurrsion
        int min_step= max(1, prev-1);
        int max_step = prev+1;

        int ind1 = lower_bound(stones.begin(), stones.end(), stones[ind] + min_step) - stones.begin(); // ele >= stone + min_step
        int ind2 = upper_bound(stones.begin(), stones.end(), stones[ind] + max_step) - stones.begin(); // ele > stone + max_step

        bool res = false;
        for(int i = ind1; i<ind2; i++) {
            res = res || f(i, stones[i] - stones[ind], stones, dp);
        }
        return dp[ind][prev] = res;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, stones, dp);
    }
};