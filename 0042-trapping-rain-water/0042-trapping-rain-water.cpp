class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, -1);
        vector<int> suffix(n, -1);

        int mx = INT_MIN;
        for(int i = 0; i<n; i++) {
            prefix[i] = max(mx, height[i]);
            mx = max(mx, prefix[i]);
        }

        mx = INT_MIN;
        for(int i = n-1; i>=0; i--) {
            suffix[i] = max(mx, height[i]);
            mx = max(mx, suffix[i]);
        }

        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans += min(prefix[i], suffix[i]) - height[i];
        }

        return ans;
    }
};