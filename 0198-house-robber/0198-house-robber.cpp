class Solution {
public:
    int f(vector<int>& nums, int index, vector<int>& dp) {
        // base case
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];

        // recurrsion
        int pick = nums[index] + f(nums, index+2, dp);
        int notpick = 0+ f(nums, index+1, dp);

        return dp[index] = max(pick, notpick);

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, 0);

        for(int index = nums.size()-1; index >= 0; index--) {
            int pick = nums[index] + dp[index+2];
            int notpick = 0+ dp[index+1];

            dp[index] = max(pick, notpick);
        }

        return dp[0];
    }
};