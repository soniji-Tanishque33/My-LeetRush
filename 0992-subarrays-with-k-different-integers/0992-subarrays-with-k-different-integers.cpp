class Solution {
public:
    int find_atmost(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int start = 0;
        int end = 0;
        int ans = 0;

        while(end < nums.size()) {
            count[nums[end]]++;
            while(count.size() > k) {
                count[nums[start]]--;
                if(count[nums[start]] == 0) count.erase(nums[start]);
                start++;
            }
            ans += end-start+1;
            end++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find_atmost(nums, k) - find_atmost(nums, k-1);
    }
};