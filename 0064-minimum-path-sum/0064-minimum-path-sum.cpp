class Solution {
public:
    int f(int i, int j, int n, int m, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return grid[0][0];

        if(i < 0 ||  j < 0) {
            return INT_MAX;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i, j-1, n, m, grid, dp);
        int left = f(i-1, j, n, m, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);


    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, n, m, grid, dp);
    }
};