class Solution {
private:
    int f(int i, int d, vector<int>& jd, vector<vector<int>>& dp) {
        int n=jd.size();
        // base case
        if(d == 1) {
            int m = jd[i];
            for(int j = i; j <n; j++) {
                m = max(m, jd[j]);
            }
            return dp[i][d] = m;
        }
        if(dp[i][d] != -1) return dp[i][d];

        // recurrsion
        int maxvalue = jd[i];
        
        int results = INT_MAX;

        for(int j = i; j<=n-d; j++) {
            maxvalue = max(maxvalue, jd[j]);
            int other = f(j+1, d-1, jd, dp);
            results = min(results, maxvalue + other);
        }
        return dp[i][d] = results;

    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));

        return f(0, d, jobDifficulty, dp);
    }
};