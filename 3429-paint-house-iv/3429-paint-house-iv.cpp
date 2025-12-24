class Solution {
public:
    int N;
    vector<int> colorMap = {1, 2, 3};
    long long dp[(long long)1e5+1][4][4];

    long long f(int index, int prev1, int prev2, vector<vector<int>>& cost) {

        if(index >= N/2) return 0;
        if(dp[index][prev1][prev2] != -1) return dp[index][prev1][prev2];

        long long result = LONG_MAX;

       
        for(int i = 0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(colorMap[i] != colorMap[j] && colorMap[i] != prev1 && colorMap[j] != prev2) {
                    result = min(result, cost[index][i] + cost[N-index-1][j] + f(index+1, colorMap[i], colorMap[j], cost));
                }
            }
        }

        return dp[index][prev1][prev2] = result;
        

    }
    long long minCost(int n, vector<vector<int>>& cost) {
        N = n;

        for(int i = 0; i<=n; i++) {
            for(int j = 0; j<4; j++) {
                for(int k = 0; k<4; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return f(0, 0, 0, cost);
    }
};