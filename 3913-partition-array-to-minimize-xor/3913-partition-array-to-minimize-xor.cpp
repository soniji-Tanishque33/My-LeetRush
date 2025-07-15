class Solution {
public:
    int solve(int i, int k, vector<int>& nums, vector<vector<int>>& dp) {
        // base case
        if(k < 0) return INT_MAX;
        if(i >= nums.size()) {
            if(k == 0) return 0;
            return INT_MAX;
        }
        if(dp[i][k] != -1) return dp[i][k];

        int _xor = 0;
        int ans = INT_MAX;
        for(int j = i; j<nums.size(); j++) {
            _xor = _xor^nums[j];
            ans = min(ans, max(_xor, solve(j+1, k-1, nums, dp)));
        }

        return dp[i][k] = ans;
    }
    int minXor(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k+1, -1));
        return solve(0, k, nums, dp);
    }
};