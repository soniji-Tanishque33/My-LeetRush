class Solution {
public:
    int f(string s, string t, int n, int m, vector<vector<int>>& dp) {
        // base case

        if(n == 0 && m == 0) return dp[n][m] = 1;
        if(m == 0) return dp[n][m] = 1;
        if(n == 0) return dp[n][m] = 0;
        
        if(dp[n][m] != -1) return dp[n][m];

        // rec
        if(s[n-1] == t[m-1]){
            return dp[n][m] = f(s, t, n-1, m-1, dp) + f(s, t, n-1, m, dp);
        }
        return dp[n][m] = f(s, t, n-1, m, dp);

    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

        for(int i = 0; i<=n; i++) {
            dp[i][0] = 1;
        }

        vector<double> prev(m+1, 0);
        vector<double> curr(m+1, 0);

        curr[0] = prev[0] = 1;

        for(int i = 1; i<=n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};