class Solution {
public:
    bool sum_equal_to_k(int i, int target, vector<int>& nums,  vector<vector<int>>&dp) {
        // base case
        if(target == 0) {
            return true;
        }

        if(i == 0) {
            if(nums[i] == target) return true;
            else return false;
        }

        if(dp[i][target] != -1) return dp[i][target];

        // take
        int take = 0;
        if(target >= nums[i]) {
            take = sum_equal_to_k(i-1, target-nums[i], nums, dp);
        }

        // not take
        int nottake = sum_equal_to_k(i-1, target, nums, dp);

        return dp[i][target] = take | nottake;
    } 
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int& x : nums) total += x;
        if(total % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>(total+1, -1));

        

        return sum_equal_to_k(n-1, total/2, nums, dp);
    }
};