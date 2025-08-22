class Solution {
public:
    int f(int i, int j, vector<vector<char>>& matrix, int& maxSq, vector<vector<int>>& dp) {
        //base case
        if(i == matrix.size() || j == matrix[0].size()) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        // recurrsion

        int right = f(i+1, j, matrix, maxSq, dp);
        int bottom = f(i, j+1, matrix, maxSq, dp);
        int bottom_right = f(i+1, j+1, matrix, maxSq, dp);

        if(matrix[i][j] == '1') {
            int minSqLen = 1+min({right, bottom, bottom_right});
            maxSq = max(maxSq, minSqLen);
            return dp[i][j] = minSqLen;
        }

        return dp[i][j] = 0;
    } 
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = n-1; i>=0; i--) {
            for(int j = m-1; j>=0; j--) {
                int right = dp[i+1][j];
                int bottom = dp[i][j+1];
                int bottom_right = dp[i+1][j+1];

                if(matrix[i][j] == '1') {
                    int minSqLen = 1+min({right, bottom, bottom_right});
                    ans = max(ans, minSqLen);
                    dp[i][j] = minSqLen;
                } else{
                    dp[i][j] = 0;
                }

            }
        }

        return ans*ans;
    }
};