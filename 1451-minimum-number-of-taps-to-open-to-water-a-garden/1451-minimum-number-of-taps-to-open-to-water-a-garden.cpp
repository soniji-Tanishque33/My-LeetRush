class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, 0); // stores the max a tap at a particular index can go
        // if there is some tap behind it that can go further then that will get the dp value

        for(int i = 0; i<ranges.size(); i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            dp[left] = max(dp[left], right);
        }

        int end = 0;
        int farthest = 0;
        int i = 0;
        int taps = 0;

        while(end < n) {
            while(i <= end) {
                farthest = max(farthest, dp[i]);
                i++;
            }

            if(farthest <= end) {
                return -1;
            }

            taps++;
            end = farthest;
        }

        return taps;

    }
};