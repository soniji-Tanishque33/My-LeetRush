class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i<n; i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]].push_back(i);
            } else {
                int last = mp[nums[i]].back();
                if(abs(i - last) <= k) return true;
                mp[nums[i]].push_back(i);
            }
        }

        return false;
    }
};

// |i-j| <= k => -k <= i-j <= k => i-k <= j <= i+k