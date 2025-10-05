class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int row = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int col = cols-1;

        while(row < rows && col >= 0) {
            if(grid[row][col] >= 0) {
                row++;
            } else {
                ans += rows-row;
                col--;
            }
        }
        return ans;
    }
};