class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        using ll = long long;
        int n = intervals.size();
        for(int i = 0; i<n; i++) intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end());

        vector dp(n+1, vector<ll>(5, -1)); // -1 means that state is not reachable
        vector path(n+1, vector(5, vector<int>())); // the path[i][j] -> what indices we have visited till i

        dp[0][0] = 0;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<=4; j++) {
                if(dp[i][j] == -1) continue;
                

                auto update = [&](int ii, int jj, ll val, bool picked) {
                    if(dp[ii][jj] > val) return;

                    vector<int> newPath = path[i][j];
                    if(picked) newPath.push_back(intervals[i][3]);
                    sort(newPath.begin(), newPath.end());
                    if(dp[ii][jj] < val || path[ii][jj] > newPath) path[ii][jj] = newPath;
                    dp[ii][jj] = val;
                };

                // not pick
                update(i+1, j, dp[i][j], false);

                if(j < 4) {
                    int next = lower_bound(intervals.begin(), intervals.end(), vector<int>{intervals[i][1]+1}) - intervals.begin();
                    update(next, j+1, dp[i][j] + intervals[i][2], true);
                }
            }
        }

        // ans will the max of all the dp[n][j] where j -> 0 till 4

        ll maxscore = 0;
        vector<int> ans;

        for(int i = 1; i<=4; i++) {
            if(maxscore > dp[n][i]) continue;
            if(dp[n][i] >  maxscore || path[n][i] < ans) {ans = path[n][i];}
            maxscore = dp[n][i];
        }

        return ans;
    }
};

// 
/**

for dp[i][j] -> till ith index we have picked j intervals
j = 0 1 2 3 4
we need dp[0< i < n+1][j <= 5]
// if we do not pick then the value at dp[i][j] will get transfered to dp[i+1][j]
// else we will update the value at i+1 j and its path
*/