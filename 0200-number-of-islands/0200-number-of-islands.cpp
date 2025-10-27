class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        q.push({i, j});
        visited[i][j] = 1;

        // top bottom left right
        int dx[] = {0 , 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int _x = p.first;
            int _y = p.second;

            for(int i = 0; i<4; i++) {
                int x = _x + dx[i];
                int y = _y + dy[i];

                if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && visited[x][y] == 0) {
                    visited[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1' && visited[i][j] == 0) {
                    bfs(grid, i, j, visited);
                    ans++;
                }
            }
        }

        return ans;
    }
};