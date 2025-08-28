class Solution {
public:
    int f(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
        // base vase
        if(r - l <= 1) return 0;
        if(dp[l][r] != -1) return dp[l][r];


        // recurrsion
        int ans= 0;

        for(int i = l+1; i<r; i++) {
            int gain = nums[l] * nums[i] * nums[r];
            int profit = gain + f(l, i, nums, dp) + f(i, r, nums, dp);
            ans = max(ans, profit);
        }

        return dp[l][r] = ans;

    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return f(0, nums.size()-1, nums, dp);
    }
};