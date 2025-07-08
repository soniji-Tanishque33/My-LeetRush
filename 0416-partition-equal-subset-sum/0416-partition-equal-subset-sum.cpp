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

        int target = total/2;
        vector<bool> curr(target+1, false), prev(target+1, false);
        // for(int i = 0; i<n; i++) dp[i][0] = true;
        // if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int i = 1; i<n; i++) {
            prev[0] = true;
            for(int j = 0; j<=target; j++) {
                 // take
                int take = 0;
                if(j >= nums[i]) {
                    take = prev[j-nums[i]];
                }

                // not take
                int nottake = prev[j];

                curr[j] = take || nottake;
            }
            prev = curr;
        }



        return prev[target];
    }
};