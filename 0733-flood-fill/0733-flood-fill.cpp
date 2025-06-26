class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> image, vector<vector<int>>& ans, int color, int initial,
        int dx[], int dy[]) {
            int n = image.size();
            int m = image[0].size();
            ans[row][col] = color;
            for(int i = 0; i<4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initial && ans[nrow][ncol] != color) {

                    dfs(nrow, ncol, image, ans, color, initial, dx, dy);
                }
            }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int initial = image[sr][sc];
        int dx[] = {0, +1, 0, -1};
        int dy[] = {+1, 0, -1, 0};
        dfs(sr, sc, image, ans, color, initial, dx, dy);

        return ans;
    }
};