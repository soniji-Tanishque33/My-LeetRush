class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<int> prefix(n+1);
        for(int i = 0; i<n; i++) {
            prefix[i+1] = prefix[i] + time[i];
        }  

        auto getsum = [&] (int l, int r) {
            if(l > r) return 0;
            return prefix[r+1]-prefix[l];
        };

        int totalsum = accumulate(time.begin(), time.end(), 0);

        // dp[index][last][removals][last_time]
        const int NP = 1e8;
        vector dp(n+1, vector(n+1, vector(k+1, vector(totalsum+1, NP))));

        // base case
        dp[1][0][0][time[0]] = (position[1] - position[0]) * time[0];

        for(int i = 1; i<n-1; i++) {
            for(int last = 0; last < i; last++) {
                for(int rem = 0; rem <= k; rem++) {
                    for(int last_time = 0; last_time <= totalsum; last_time++) {
                        int dist = position[i+1] - position[i];
                        int total_time_before = getsum(last+1, i);

                        // we keep
                        dp[i+1][i][rem][total_time_before] = min(dp[i+1][i][rem][total_time_before], dp[i][last][rem][last_time] + total_time_before * dist);

                        // we remvoe
                        if(rem < k) {
                            dp[i+1][last][rem+1][last_time] = min(dp[i+1][last][rem+1][last_time], dp[i][last][rem][last_time] + dist * last_time);
                        }
                    }
                }
            }
        }

        int ans = NP;

        for(int last = 0; last<n; last++) {
            for(int last_time = 0; last_time <= totalsum; last_time++) {
                ans = min(ans, dp[n-1][last][k][last_time]);
            }
        }

        return ans;
    }
};