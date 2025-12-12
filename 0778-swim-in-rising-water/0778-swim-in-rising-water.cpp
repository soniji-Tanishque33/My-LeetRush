class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        // maxheight, row, col

        pq.push({grid[0][0], 0, 0});

        // top bottom left right
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int time = 0;

        while(pq.size()) {
            auto [currmax, x, y] = pq.top();
            pq.pop();
            time++;
            if(x == n-1 && y == n-1) return currmax;

            for(auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                
                if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int nextmax = max(currmax, grid[nx][ny]);

                    if(nextmax <  dist[nx][ny]) {
                        dist[nx][ny] = nextmax;
                        pq.push({nextmax, nx, ny});
                    }
                }
            }
        }

        return -1;


    }
};