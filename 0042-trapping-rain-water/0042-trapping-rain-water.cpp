class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> max_prefix(n), max_suffix(n);
        int mx = INT_MIN;

        for(int i = 0; i<n; i++) {
            max_prefix[i] = max(mx, height[i]);
            mx = max_prefix[i];
        }

        mx = INT_MIN;
        for(int i = n-1; i>=0; i--) {
            max_suffix[i] = max(mx, height[i]);
            mx = max_suffix[i];
        }

        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans += min(max_suffix[i], max_prefix[i]) - height[i];
        }

        return ans;
    }
};