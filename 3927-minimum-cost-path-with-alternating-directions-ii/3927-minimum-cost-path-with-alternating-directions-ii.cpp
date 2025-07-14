class Solution {
public:
    using ll = long long;
    long long f(int x, int y, int time, vector<vector<int>>& waitC, vector<vector<vector<ll>>>& dp) {
        // base case
        int m = waitC.size();
        int n = waitC[0].size();

        if(x == m || y == n) return LLONG_MAX;
        if(x == m-1 && y == n-1) {
            return 0;
        }
        if(dp[x][y][time%2] != -1) return dp[x][y][time%2];

        long long cost = LLONG_MAX;
        if(time%2 == 0) {
        // even
            cost = waitC[x][y] + f(x, y, time+1, waitC, dp);
        } else {
        // odd
            long long right = f(x+1, y, time+1, waitC, dp);
            long long up = f(x, y+1, time+1, waitC, dp);

            if(right != LLONG_MAX) cost = min(cost, (x+2)*(y+1) + right);
            if(up != LLONG_MAX) cost = min(cost,(x+1)*(y+2) + up);
        }
        return dp[x][y][time%2] = cost;
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(2, -1)));
        return 1 + f(0, 0, 1, waitCost, dp);
    }
};