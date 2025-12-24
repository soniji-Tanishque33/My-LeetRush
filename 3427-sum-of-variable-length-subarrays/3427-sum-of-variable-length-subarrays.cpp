class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            int start = max(0, i - nums[i]);
            for(int j =start; j<=i; j++) {
                ans += nums[j];
            }
        }

        return ans;
    }
};