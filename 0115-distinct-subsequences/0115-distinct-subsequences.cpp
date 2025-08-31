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

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(s, t, n, m, dp);
    }
};