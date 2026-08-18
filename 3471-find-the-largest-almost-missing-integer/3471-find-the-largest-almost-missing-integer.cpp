class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for(int i = 0; i<n; i++) {
            int j = i+k-1;
            set<int> visited;
            if(j >= n) continue;
            for(int k = i; k <=j; k++) {
                if(!visited.count(nums[k])) freq[nums[k]]++;
                visited.insert(nums[k]);
            }
        }

        // for(auto it: freq) {
        //     cout << it.first << " " << it.second << endl;
        // }

        int ans = INT_MIN;
        for(auto it: freq) {
            if(it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        if(ans != INT_MIN) return ans;

        return -1;
    }
};