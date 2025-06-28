class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // top right bottom left
            int dx[] = {0, +1, 0, -1};
            int dy[] = {+1, 0 ,-1, 0};

            
            for(int i=0; i<4; i++) {
                int nrow = r + dx[i];
                int ncol = c + dy[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == '1' && visited[i][j] == 0) {
                    bfs(i, j, visited, grid);
                    ans++;
                }
            }
        }


        return ans;
    }
};