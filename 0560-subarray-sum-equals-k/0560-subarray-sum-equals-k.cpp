class Solution {
public:
    
    int subarraySum(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        int prefix_sum = 0;
        for(int i = 0; i<n; i++) {
            prefix_sum += nums[i];
            if(prefix_sum == target) ans++;
    
            if(mp.find(prefix_sum-target) != mp.end()) {
                ans += mp[prefix_sum-target];
            } 

            mp[prefix_sum]++;
        }
        return ans;
    }
};